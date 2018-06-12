#include "bits/stdc++.h"
#define len 1000001
using namespace std;

typedef int ll;
typedef unsigned long long int llu;
ll sp[len];
ll dp[len];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);


    for (ll i=1; i<len; i++)
        sp[i] = i;

    for(ll i=4; i<len; i+=2)
        sp[i]=2;

    for(ll i=3; i*i<len; i+=2)
    {
        if(sp[i]==i)
        {
            for(ll j=i*i; j<len; j+=i)
                if(sp[j]==j)
                    sp[j]=i;
        }
    }

    ll cnt=0;
    dp[0]=0;
    for(ll i=1; i<len; i++)
    {
        ll x=i;
        while(x!=1)
        {
            ll tmp=x/sp[x];
            if(sp[tmp]==sp[x])
                break;
            x=x/sp[x];
        }
        if(x==1)
            cnt++;
        dp[i]=cnt;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        if(l==0)
            l=1;
        cout<<dp[r]-dp[l-1]<<"\n";
    }

    return 0;
}

