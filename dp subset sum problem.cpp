#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    bool T[n+1][s+1]={0};
    for(int i=0;i<=n;i++)
        T[i][0]=true;

    for(int j=1;j<=s;j++)
        T[0][j]=false;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(j<a[i-1])
                T[i][j]=T[i-1][j];
            else
                T[i][j] = T[i-1][j] || T[i-1][j-a[i-1]];
        }
    }
    if(T[n][s])
        cout<<"YES";
    else
        cout<<"NO";
}

