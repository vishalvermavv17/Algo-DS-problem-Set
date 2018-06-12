#include <bits/stdc++.h>
using namespace std;

void constructSegTree(long long int input[], long long int * st, int low, int high, long long int pos)
{
    if(low==high)
    {
        st[pos]=input[low];
        return;
    }
    int mid=(low+high)/2;
    constructSegTree(input, st, low, mid, 2*pos+1);
    constructSegTree(input, st, mid+1, high,2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}


long long int rangeSumQuery(long long int* st, int ql, int qh, int low, int high, long long int pos)
{
    if(ql <= low && qh >= high)
        return st[pos];

    else
        if(ql > high || qh < low)
            return 0;
    else {
        int mid=(low+high)/2;
        return (rangeSumQuery(st, ql, qh, low, mid, 2*pos+1) + rangeSumQuery(st, ql, qh, mid+1, high, 2*pos+2));
    }
}

void updateQuery(long long int *st, int low, int high, long long int pos, int i, int x)
{
    if(low==i && high==i)
    {
        st[pos]+=x;
        return;
    }
    st[pos]+=x;
    int mid=(low+high)/2;
    if(i <= mid)
        updateQuery(st, low, mid, 2*pos+1, i, x);
    else
        updateQuery(st, mid+1, high, 2*pos+2, i, x);
}

int main()
{
    int n;
    cin>>n;

    long long int input[n];

    for(int i=0; i<n; i++)
        cin>>input[i];

    long long int maxSize = (long long int) pow(2,ceil(log2(n)))*2-1;

    long long int *st = new long long int[maxSize];

    constructSegTree(input, st, 0, n-1, 0);

    int q;
    cin>>q;
    while(q--)
    {
        char qry;
        cin>>qry;
        switch(qry)
        {
            case 'q' :  int l,r;
                        cin>>l>>r;
                        cout<<rangeSumQuery(st, l-1, r-1, 0, n-1, 0)<<"\n";
                        break;

            case 'u' :  int i;
                        long long int x;
                        cin>>i>>x;
                        updateQuery(st, 0, n-1, 0, i-1, x);

        }
    }
}
