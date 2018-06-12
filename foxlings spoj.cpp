#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct fnode{
    ll A;
    ll B;
};


struct node{
    ll rank;
    node *parent;
};

map <ll, node*> m;
map <ll,int> mp;

node* makePair(ll data)
{
    node *root=new node;
    root->rank=0;
    root->parent=root;
    return root;
}
node* findSet(node *);
void makeUnion(ll x, ll y)
{
    node *node1=m[mp[x]];
    node *node2=m[mp[y]];

    node* parent1=findSet(node1);
    node *parent2=findSet(node2);

    if(parent1 == parent2)
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
    if(root == parent || !parent)
    {
        return parent;
    }
    root->parent=findSet(root->parent);
    return root->parent;
}

bool cmp(fnode x, fnode y)
{
    if(x.A == y.A)
        return x.B < y.B;
    return x.A < y.A;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;

    fnode a[q];
    for(int i=0; i<q; i++)
        cin>>a[i].A>>a[i].B;

    sort(a,a+q,cmp);


    int cnt=0;
    for(int i=0; i<q; i++)
    {
        if(!mp[a[i].A])
            mp[a[i].A]=++cnt;
        if(!m[mp[a[i].A]])
            m[mp[a[i].A]]=makePair(a[i].A);

        if(!mp[a[i].B])
            mp[a[i].B]=++cnt;
        if(!m[mp[a[i].B]])
            m[mp[a[i].B]]=makePair(a[i].B);

        makeUnion(a[i].A, a[i].B);
    }
    q=n-cnt;
    for(int i=1; i<=cnt; i++)
    {
        node *Nd;
        if(m[i])
         {
             Nd=findSet(m[i]);
         }
        if(Nd)
        {
            Nd->parent=NULL;
            q++;
        }
    }
    cout<<q;
    return 0;
}
