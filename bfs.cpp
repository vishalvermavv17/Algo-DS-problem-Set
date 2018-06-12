#include <iostream>
using namespace std;

int main()
{
    queue <int> q;
    int n,m;
    cin>>n>>m;
    int a[n][n]={0};

    while(m--)
    {
        int i,j;
        cin>>i>>j;
        a[i-1][j-1]=a[j-1][i-1]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i][j]==1)
                cout<<a[i][j]<<" ";
            else
                cout<<"0"<<" ";
        cout<<endl;
    }

    q.push(1);
    visited(1)=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node;
        for()
        {
            if(adj[node][i]==1 && !visited[node[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return 0;
}

