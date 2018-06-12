#include"bits/stdc++.h"
using namespace std;

int main()
{
    /*int n;
    cin>>n;

    int input[n];
    for(int i=0; i<n; i++)
        cin>>input[i];

    int ft[n+1]={0};

    for(int i=0; i<n; i++)
    {
        ft[i+1]+=input[i];
        int idx=(i+1)+((i+1)&(-i-1));
        cout<<idx<<" ";
        while( idx < n+1 )
        {
            ft[idx]+=input[i];
            idx=(idx)+((idx)&((idx^1048575)+1));
            cout<<idx<<" ";
        }
        cout<<"\n";

    }

    for(int i=0; i<=n; i++)
        cout<<ft[i]<<" ";

    int q;
    cin>>q;
    while(q--)
    {
        int ql,qh;
        cin>>ql>>qh;

        int sum;
        sum=ft[qh+1];
        int idx=(qh+1)-((qh+1)&(((qh+1)^1048575)+1));

        while( idx > 0 )
        {
            sum+=ft[idx];
            idx=(idx)-((idx)&(((idx)^1048575)+1));
        }

        int diff=ft[ql];
        idx=(ql)-((ql)&(((ql)^1048575)+1));

        while( idx > 0 )
        {
            diff+=ft[idx];
            idx=(idx)-((idx)&(((idx)^1048575)+1));
        }
        cout<<sum-diff<<"\n";
    }*/
    int n,u;
        cin>>n>>u;
        int ft[n+1]={0};
        while(u--)
        {
            int l,r,value;
            cin>>l>>r>>value;
            for(int i=l; i<=r; i++)
            {
                ft[i+1]+=value;
                int idx=(i+1)+((i+1)&-(i+1));
                while(idx < n+1)
                {
                    ft[idx]+=value;
                    idx=idx+((idx)&-idx);
                }
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int ql;
            cin>>ql;
            int sum;
            sum=ft[ql+1];
            int idx=(ql+1)-((ql+1)&-(ql+1));

            while( idx > 0 )
            {
                sum+=ft[idx];
                idx=(idx)-((idx)&-(idx));
            }

            int diff=ft[ql];
            idx=(ql)-((ql)&-(ql));

            while( idx > 0 )
            {
                diff+=ft[idx];
                idx=(idx)-((idx)&-(idx));
            }
            cout<<sum-diff<<"\n";
        }
}
