#include <bits/stdc++.h>
using namespace std;
int level;
int arr[4];
int visited[10000]={0};
queue <int> q;
vector <vector <int> > v(100);

void bfs(int a,int b,int M,int D,int A,int S)
{

    arr[0]=a*M; arr[1]=a/D; arr[2]=a+A; arr[3]=a-S;
    for(int i=0;i<4;i++)
    {
        q.pop();
        if(arr[i]>1 && arr[i]<1000000 && !visited[arr[i]])
        {
            v[a].push_back(arr[i]);
            q.push(arr[i]);
            if(arr[i]==b)
                break;
        }
        else
        {
            level++;
        }
        bfs(q.front(),b,M,D,A,S);
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    int n,m,t,a,b,M,D,A,S;
    cin>>t;
    while(t--)
    {
        level=0;

       cin>>a>>b;
       cin>>M>>D>>A>>S;
       visited[10000]={0};
       visited[a]=1;

       q.push(a);
       bfs(a,b,M,D,A,S);
       cout<<level;

    }

}

