#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i,n,j,t;
    cin>>t;
    while(t--)
    {
        queue <int> q;
    vector <vector<int> > v(1000);
        cin>>n;
        bool visited[100009]={false};
        int level[1000];
        for(i=1;i<=n;i++)
        {
            cin>>j;
            if(i+1>0 && i+j<=n && i!=n)
                v[i].push_back(i+1);
            if(i+j>0 && i+j<=n )
                v[i].push_back(i+j);
        }


        q.push(1);
        visited[1]=true;
        level[1]=0;
        int node;
        while(!q.empty())
        {
            node=q.front();
            if(node==n)
                break;
            for(j=0;j<v[node].size();j++)
            {
                if(!visited[v[node][j]])
                {
                    q.push(v[node][j]);
                    visited[v[node][j]]=true;
                    level[v[node][j]]=level[node]+1;
                }
            }
            q.pop();
        }
        cout<<level[node]+1<<endl;
    }

}
