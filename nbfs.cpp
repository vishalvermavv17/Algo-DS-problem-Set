#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,visited[10]={0},t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n][n]={0};

        while(m--)
        {
            int i,j;
            cin>>i>>j;
            a[i][j]=a[j][i]=1;
        }

        queue <int> q;
        q.push(1);

        while(!q.empty())
        {
            int node=q.front();
            cout<<node;
            q.pop();
            visited[node]=1;
            for(int i=1;i<=n;i++)
            {
                if(a[node][i] && !visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                }
            }

        }
    }
}
