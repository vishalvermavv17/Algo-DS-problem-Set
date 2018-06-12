#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node{
    int rank;
    node *parent;
    int data;
};

node* makePair(int data)
{
    node *root=new node;
    root->data=data;
    root->rank=0;
    root->parent=root;
    return root;
}
node* findSet(node *);
void makeUnion(int x, int y, map<int,node*> m)
{
    node *node1=m[x];
    node *node2=m[y];

    node* parent1=findSet(node1);
    node *parent2=findSet(node2);

    if(parent1->data == parent2->data)
        return;

    if(parent1->rank >= parent2->rank)
    {
        parent1->rank=(parent2->rank==parent1->rank)? parent1->rank+1:parent1->rank;
        parent2->parent=parent1;
    }
    else
        parent1->parent=parent2;
}

node* findSet(node *root)
{
    node *parent=root->parent;
    if(root == parent)
    {
        return parent;
    }
    root->parent=findSet(root->parent);
    return root->parent;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];
    map <int, node*> m;
    for(int i=0; i<n; i++)
        m[a[i]]=makePair(a[i]);

    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        makeUnion(x,y,m);
    }
    cin>>q;
    while(q--)
    {
        int u;
        cin>>u;
        cout<<(findSet(m[u]))->data<<"\n";
    }
    return 0;
}
