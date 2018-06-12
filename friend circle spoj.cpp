#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node{
    node* parent;
    int rank;
    char fn[25];
};
map<string,node*> m;


node* makePair(char fn[])
{
    node *root=new node;
    root->parent=root;
    root->rank=1;
    strcpy(root->fn,fn);
    return root;
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

int makeUnion(node *node1, node* node2)
{
    node *parent1=findSet(node1);
    node *parent2=findSet(node2);

    if(parent1 == parent2)
        return parent1->rank;
    if(parent2->rank >= parent1->rank)
    {
        parent1->parent=parent2;
        parent2->rank=parent1->rank+parent2->rank;
        return parent2->rank;
    }
    else
    {
        parent2->parent=parent1;
        parent1->rank+=parent2->rank;
        return parent1->rank;
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
        m.clear();
        int n;
        cin>>n;
        while(n--)
        {
          char f1[25],f2[25];
          cin>>f1>>f2;
          if(!m[f1])
            m[f1]=makePair(f1);

          if(!m[f2])
            m[f2]=makePair(f2);

          node *parent1=findSet(m[f1]);
          node *parent2=findSet(m[f2]);
          cout<<makeUnion(m[f1], m[f2])<<"\n";

        }
    }

    return 0;
}

