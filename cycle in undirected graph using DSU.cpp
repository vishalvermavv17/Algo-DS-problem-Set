#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct vertex
{
    vertex * parent;
};
vertex* v[10007];

vertex* makeSet()
{
    vertex *v=new vertex;
    v->parent=v;
    return v;
};

vertex* findSet(vertex* v)
{
    vertex* parent=v->parent;
    if(parent==v)
        return parent;
    v->parent=findSet(parent);
    return v->parent;
}

void Union(vertex* v1, vertex* v2)
{
    vertex* p1=findSet(v1);
    vertex* p2=findSet(v2);

    if(p1 == p2)
        return;
    p2->parent=p1;
        return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    register int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        v[i]=makeSet();

    register int m;
    scanf("%d",&m);
    bool flag=1;
    while(m--)
    {
        flag=0;
        int x,y;
        scanf("%d%d",&x,&y);

        vertex* v1=findSet(v[x-1]);
        vertex* v2=findSet(v[y-1]);
        if(v1 == v2)
        {
            flag=1;
            break;
        }
        Union(v1, v2);
    }
    if(flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}


