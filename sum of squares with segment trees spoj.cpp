#include<bits/stdc++.h>
using namespace std;

long long int squareSumQuery(long long int *segTree, int st, int nd, int low, int high, long long int pos)
{
    if(st > high || nd < low)
        return 0;
    if(st <= low && nd >= high)
        return segTree[pos];

    int mid=(low+high)/2;
    return (squareSumQuery(segTree, st, nd, low, mid, 2*pos+1)+squareSumQuery(segTree, st, nd, mid+1, high, 2*pos+2));

}



void incrementInRange(long long int * segTree, int x, int low, int high, long long int pos)
{
    if(low==high)
    {
        segTree[pos]+=x;
        segTree[pos]*=segTree[pos];
        return;
    }
    int mid=(low+high)/2;
    incrementInRange(segTree, x, low, mid, 2*pos+1);
    incrementInRange(segTree, x, mid+1, high, 2*pos+2);
    segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}


void updateSegTree(long long int * segTree, int st, int nd, int x, int low, int high, long long int pos)
{
    if(st > high || nd < low)
        return;
    if(st <= low && nd >= high)
    {
        incrementInRange(segTree, x, low, high, pos);
        return;
    }
    int mid=(low+high)/2;
    updateSegTree(segTree, st, nd, x, low , mid, 2*pos+1);
    updateSegTree(segTree, st, nd, x, mid+1, high, 2*pos+2);
    segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}


void setConstValue(long long int * segTree, int x, int low, int high, long long int pos)
{
    if(low==high)
    {
        segTree[pos]=(long long int)x*x;
        return;
    }
    int mid=(low+high)/2;
    setConstValue(segTree, x, low, mid, 2*pos+1);
    setConstValue(segTree, x, mid+1, high, 2*pos+2);
    segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}


void setSameNo(long long int * segTree, int st, int nd, int x, int low, int high, long long int pos)
{
    if(st > high || nd < low)
        return;
    if(st <= low && nd >= high)
    {
        setConstValue(segTree, x, low, high, pos);
        return;
    }
    int mid=(low+high)/2;
    setSameNo(segTree, st, nd, x, low , mid, 2*pos+1);
    setSameNo(segTree, st, nd, x, mid+1, high, 2*pos+2);
    segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];

}

void constructTree(int a[], long long int *st, int low, int high, long long int pos)
{
    if(low==high)
    {
        st[pos]=a[low]*a[low];
        return;
    }
    int mid=(low+high)/2;
    constructTree(a, st, low, mid, 2*pos+1);
    constructTree(a, st, mid+1, high, 2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}


int main()
{
    int t,Cn;
    cin>>t;
    Cn=t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        long long int maxSize = pow(2,ceil(log2(n)))*2-1;
        long long int * segTree = new long long int[maxSize];
        constructTree(a, segTree, 0, n-1, 0);

        int st,nd,x;
        cout<<"Case "<<Cn-t<<":\n";
        while(q--)
        {
            int qry;
            cin>>qry;
            switch(qry)
            {
                case 0 :    cin>>st>>nd>>x;
                            setSameNo(segTree, st-1, nd-1, x, 0, n-1, 0);
                            break;

                case 1 :    cin>>st>>nd>>x;
                            updateSegTree(segTree, st-1, nd-1, x,0, n-1, 0);
                            break;

                case 2 :    cin>>st>>nd;
                            cout<<squareSumQuery(segTree, st-1, nd-1, 0, n-1, 0)<<"\n";
            }
        }

    }
}
