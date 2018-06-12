#include <bits/stdc++.h>
using namespace std;


long long int rangeMinQuery(long long int *st, int ql, int qh, int low, int high, long long int pos)
{
    if(ql <= low && high <= qh )
        return st[pos];
    else
        if(ql >high || qh < low)
            return 1000000009+1;
    else
    {
        int mid=(low+high)/2;
        return min(rangeMinQuery( st, ql, qh, low, mid, 2*pos+1), rangeMinQuery(st, ql, qh, mid+1, high, 2*pos+2));
    }

}


void constructTree( long long int input[], long long int *st, int low, int high, long long int pos)
{
    if(low==high)
    {
        st[pos]=input[low];
        return;
    }

    int mid=(low+high)/2;
    constructTree( input, st, low, mid, 2*pos+1 );
    constructTree( input, st, mid+1, high, 2*pos+2);
    st[pos]=min(st[2*pos+1], st[2*pos+2]);
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    int t,caseNo=0;
    cin>>t;
    while(t--)
    {
        caseNo++;
        int n,q;
        cin>>n>>q;
        long long int input[n];
        for(int i=0; i<n; i++)
            cin>>input[i];
        long long int maxSize=(long long int) pow(2,ceil(log2(n)))*2-1;

        long long int * st =  new long long int[maxSize];

        int  low=0, high=n-1;
        long long int pos=0;
        constructTree( input, st, low, high, pos );
        cout<<"Scenario #"<<caseNo<<":\n";
        while(q--)
        {
            int ql,qh;
            cin>>ql>>qh;
            long long int minimum = rangeMinQuery(st, ql-1, qh-1, low, high, pos);
            cout<<minimum<<"\n";
        }
    }
    return 0;
}
