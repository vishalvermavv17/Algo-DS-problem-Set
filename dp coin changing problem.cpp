#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int T[n+1][s+1];
    for(int j=0;j<=s;j++)
        T[0][j]=j;

    for(int i=0;i<=n;i++)
        T[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(j<a[i-1])
                T[i][j]=T[i-1][j];
            else
                T[i][j]=min(T[i-1][j], 1+T[i-1][j-a[i-1]]);
        }
    }
    if(T[n][s]!=100)
    cout<<T[n][s];
    else
       cout<<-1;
}
