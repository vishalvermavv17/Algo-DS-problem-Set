#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    ll a[n],b[n];
    for( int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];

    int temp,idx=0;
    temp=(b[0]<0) ? -b[0]:b[0];

    for(int i=1; i<n; i++)
    {
        if(b[i] < 0)
        {
            if(temp == -b[i])
            {
                if(a[idx] < a[i])
                {
                    temp=-b[i];
                    idx=i;
                }
            }
            if(temp < -b[i])
            {
                temp=-b[i];
                idx=i;
            }
        }
        else
        {
            if(temp == b[i])
            {
                if(a[idx] > a[i])
                {
                    temp=b[i];
                    idx=i;
                }
            }
            if(temp < b[i])
            {
                temp=b[i];
                idx=i;
            }
        }
    }
    if(b[idx]<0)
    {
        while(k--)
        {
            a[idx]+=2;
        }
    }
    else
    {
        while(k--)
            a[idx]-=2;
    }
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i]*b[i];
    }
    cout<<sum;

    return 0;
}

