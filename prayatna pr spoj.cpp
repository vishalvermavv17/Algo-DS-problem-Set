#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node
{
    int data ;
    node* next;
};
node* v[100007];
int visited[100007]={false};

node* insertNode(node *a, int y)
{
    if(!a)
    {
        node *newNode=new node;
        newNode->data=y;
        newNode->next='\0';
        return newNode;
    }
    a->next=insertNode(a->next, y);
    return a;
}

void dfs(int x)
{
    if(visited[x])
        return;
    visited[x]=true;
    node* currNode=v[x];
    while(currNode)
    {
        dfs(currNode->data);
        currNode=currNode->next;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;

        for(int i=0; i<n; i++)
            visited[i]=false;

        for(int i=0; i<n; i++)
            v[i]='\0';

        while(e--)
        {
            int a,b;
            cin>>a>>b;
            v[a]=insertNode(v[a],b);
            v[b]=insertNode(v[b],a);
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i);
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
