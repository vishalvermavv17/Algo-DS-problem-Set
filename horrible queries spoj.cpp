#include<bits/stdc++.h>
using namespace std;

long long int lazyMinRangeQuery(long long int *st, long long int *lazy, int ql, int qh, long int low, long int high, long long int pos)
{
    if(lazy[pos]!=0)
    {
        st[pos]+=(long long int)(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    //no overlap
    if(ql>high || qh<low)
            return 0;

    //total Overlap
    if(ql <= low && qh >= high)
            return st[pos];

    //partial overlap
    long int mid=(low+high)/2;
    return (lazyMinRangeQuery(st, lazy, ql, qh, low, mid, 2*pos+1)+lazyMinRangeQuery(st, lazy, ql, qh, mid+1, high, 2*pos+2));

}

void updateMinRangeSegTree(long long int* st, long long int *lazy, int ql, int qh, long long int delta, long int low, long int high, long long int pos)
{
    if(lazy[pos]!=0)//execute when update is required
    {
        st[pos]+=(long long int)(high-low+1)*lazy[pos];
        if(low!=high)//if it is not a leaf node
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }

    //no overlap
    if(ql>high || qh<low)
        return;


    //total Overlap
    if(ql <= low && qh >= high)
    {
        st[pos]+=(long long int)(high-low+1)*delta;
        if(low!=high)
        {
            lazy[2*pos+1]+=delta;
            lazy[2*pos+2]+=delta;
        }
        return;
    }

    //partial overlap
    long int mid=(low+high)/2;
    updateMinRangeSegTree(st, lazy, ql, qh, delta, low, mid, 2*pos+1);
    updateMinRangeSegTree(st, lazy, ql, qh, delta, mid+1, high, 2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}


void constructTree(int input[], long long int *st, long int low, long int high, long long int pos)
{
    if(low==high)
    {
        st[pos]=input[low];
        return;
    }

    long int mid=(low+high)/2;
    constructTree(input, st, low, mid, 2*pos+1);
    constructTree(input, st, mid+1, high, 2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}

int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int n,c;
        cin>>n>>c;

        int input[n]={0};

        long long int maxSize=(long long int) pow(2,ceil(log2(n)))*2-1;

        long long int *st =  new   long long int[maxSize];
        long long int *lazy= new   long long int[maxSize];
        for(long long int i=0; i<maxSize; i++)
            lazy[i]=0;

        constructTree(input, st, 0, n-1, 0);
        while(c--)
        {
            int qry,ql,qh;
            long long int delta;
            cin>>qry;
            switch(qry)
            {
                case 0 :    cin>>ql>>qh>>delta;
                            updateMinRangeSegTree(st, lazy, ql-1,qh-1, delta, 0, n-1, 0);
                            break;

                case 1 :    cin>>ql>>qh;
                            cout<<lazyMinRangeQuery(st, lazy, ql-1, qh-1, 0, n-1, 0)<<"\n";
            }

        }

    }


}
