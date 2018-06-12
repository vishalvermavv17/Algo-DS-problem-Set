#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node
{
    int data;
    node* next;
}*v[100007];
bool visited[100007];
int tmp=0,qlen;
queue<int> q;


node* insertNode(node* a, int y)
{
    if(!a)
    {
        node* newNode=new node;
        newNode->data=y;
        newNode->next='\0';
        return newNode;
    }
    a->next=insertNode(a->next, y);
    return a;
}

void findLenBFS()
{
    bool visited[100007]={false};
    while(!q.empty())
    {
        int x=q.front();
        node* currNode=v[x];
        visited[x]=true;
        q.pop();

        while(currNode)
        {
            if(!visited[currNode->data])
            {
                visited[currNode->data]=true;
                q.push(currNode->data);
            }
            currNode=currNode->next;
        }
        qlen--;
        if(!qlen)
        {
            tmp++;
            qlen=q.size();
        }
    }
    return ;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            v[i]='\0';
        for(int i=1; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            v[a]=insertNode(v[a], b);
            v[b]=insertNode(v[b], a);
        }
        int len=100007;
        for( int i=0; i<n; i++)
        {
            tmp=0,qlen=1;
            q.push(i);

            findLenBFS();
            if(tmp < len)
                len=tmp;
        }
        cout<<len-1<<"\n";
    }

    return 0;
}


