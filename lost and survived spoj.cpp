#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
int a[100009]={0};
struct node{
    int rank;
    node *parent;
};

node* makePair()
{
    node *root=new node;
    root->rank=1;
    root->parent=root;
    return root;
}

node* findSet(node *root)
{
    node *parent=root->parent;
    if(root == parent)
        return parent;
    root->parent=findSet(parent);
    return root->parent;
}


int makeUnion(node *node1, node* node2)
{
    node* parent1=findSet(node1);
    node* parent2=findSet(node2);

    if(parent1 == parent2)
        return parent1->rank;
    if(parent1->rank >= parent2->rank)
    {
        a[parent2->rank]--; a[parent1->rank]--;
        parent1->rank+=parent2->rank;
        parent2->rank=parent1->rank;
        parent2->parent=parent1;
        a[parent1->rank]++;
        return parent1->rank;
    }
    else
    {
        a[parent1->rank]--; a[parent2->rank]--;
        parent1->rank+=parent2->rank;
        parent2->rank=parent1->rank;
        parent1->parent=parent2;
        a[parent2->rank]++;
        return parent2->rank;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    a[1]=n;
    map <int , node*> m;
    for(int i=0; i<n; i++)
        m[i]=makePair();
    int high=1,low=1;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int temp=makeUnion(m[x-1], m[y-1]);
        if(temp > high)
            high=temp;

        if(!a[low])
            while(!a[low])
                low++;
        cout<<high-low<<"\n";

    }

    return 0;
}

