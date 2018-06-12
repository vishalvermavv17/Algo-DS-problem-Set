#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int> > v(100);
    int tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tmp;
            v[i].push_back(tmp);
        }
    }
    int color[100],visited[100]={0};
    for(int i=0; i<100; i++)
        color[i]=-1;
    color[0]++;
    visited[0]=1;
    queue<int> q;
    q.push(0);
    int i;
    while(!q.empty()){
        i=q.front();
        tmp=color[i];
        for(vector<int>::iterator it=v[i].begin(); it != v[i].end(); it++){
            if(color[*it] == tmp){
                cout<<"Not Bipartite";
                return 0;
            }
            else if(color[*it] == -1){
                color[*it]=tmp==0 ? 1:0;
            }
            if(!visited[*it])
            {
                q.push(*it);
                visited[*it]=1;
            }

        }
        q.pop();
    }
    cout<<"Yes Bipartite";
    return 0;

}
