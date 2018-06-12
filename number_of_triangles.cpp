#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,visited[10]={0},count=0,t;
    cin>>n>>m;
    int a[n+2][n+2]={0};

    while(m--)
    {
        int i,j;
        cin>>i>>j;
        a[i][j]=a[j][i]=1;
    }

    for(int i=1;i<=n;i++)
    {
        int node=i;
        for(int j=1;j<=n;j++)
        {
            if(a[node][j]==1 && a[j][node]==1)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i][node]>0 && a[i][j]>0 && i!=node && i!=j)
                        count++;
                }
            }
        }
    }
    cout<<count/6;

    return 0;
}

