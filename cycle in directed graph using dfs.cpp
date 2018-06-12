#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
bool visited[10000]={false};
struct node
{
    int data;
    node* next;
}*v[10000];

bool recStack[10000]={false};

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

bool isCycle(int x)
{
    if(visited[x])
        return false;
    visited[x]=1;
    recStack[x]=1;
    node* currNode=v[x-1];
    while(currNode)
    {
        if(!visited[currNode->data] && isCycle(currNode->data))
            return true;
        else if(recStack[currNode->data])
            return true;
        currNode=currNode->next;
    }
    recStack[x]=false;
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
    }
    bool ans=false;
    for( int i=1; i<=n && !ans; i++)
    {
        ans=isCycle(i);
    }
    if(ans)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}


