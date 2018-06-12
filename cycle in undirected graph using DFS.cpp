#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node
{
    int vertex ;
    node* next;
};
node* v[10007];
int visited[10007]={false};


node* insertNode(node *a, int y)
    {
        if(!a)
        {
            node *newNode=new node;
            newNode->vertex=y;
            newNode->next='\0';
            return newNode;
        }
        a->next=insertNode(a->next, y);
        return a;
    }

bool cycleCheckDfs(int x, int parent)
{
    if(visited[x])
        return false;
    visited[x]=true;
    node* currNode;
    currNode=v[x-1];
    while(currNode)
    {
        if(visited[currNode->vertex] && currNode->vertex!=parent)
            return true;
        if(currNode->vertex != parent)
        {
            bool flag=cycleCheckDfs(currNode->vertex, x);
            if(flag)
                return true;
        }
        currNode=currNode->next;
    }
    return false;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        v[i]='\0';
    }

    int m;
    cin>>m;

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        v[x-1]=insertNode(v[x-1], y);
        v[y-1]=insertNode(v[y-1], x);
    }
    bool ans=false;
    if(n == 0)
        ans=true;
    else
        for(int i=1; i<=n && !ans; i++)
            ans=cycleCheckDfs(i, 0);
    if(ans)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}


