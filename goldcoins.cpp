#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int dp[n];
    dp[0]=a[0];
    if(n>1)
    dp[1]=a[1];
    if(n>2)
    dp[2]=a[0]+a[2];

    for(int i=3;i<n;i++)
        dp[i]=max(dp[i-2]+a[i],dp[i-3]+a[i]);

        int ans;
    if(n>1)
        ans=max(dp[n-1],dp[n-2]);
    else
        ans=dp[0];

    cout<<ans;
    return 0;
}
