#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node
{
    int data ;
    node* next;
};
node* v[10007];
int visited[10007]={false};
int tmp;
//insert the node in the adjacency list
node* insertNode(node* a, int y)
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
//find longest path for each node
void dfsPath(int x)
{
    if(!visited[x])
    {
        visited[x]=true;
        tmp++;
        node* currNode=v[x-1];
        while(currNode)
        {
            dfsPath(currNode->data);
            currNode=currNode->next;
        }
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        v[i]='\0';

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a-1]=insertNode(v[a-1],b);
    }

    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            visited[j]=false;

        tmp=0;
        dfsPath(i);
        if(cnt < tmp)
            cnt=tmp;
    }
    cout<<cnt;
    return 0;
}
