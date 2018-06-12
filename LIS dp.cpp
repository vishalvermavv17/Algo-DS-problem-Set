#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
                dp[i]=max(dp[j]+1,dp[i]);
        }
        cout<<dp[i]<<"\n";
    }
    //cout<<dp[n-1];
    int temp=dp[0];
    for(int i=1;i<n;i++)
        if(temp<dp[i])
            temp=dp[i];
    cout<<temp;
}
