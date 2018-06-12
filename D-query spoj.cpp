#include <bits/stdc++.h>
using namespace std;

#define N 31111
#define block 200
#define A 1000007

int cnt[A],ANS=0,a[N];

struct node{
    int l,r,i;
};


bool comp(node x, node y)
{
    if(x.l/block != y.l/block)
        return x.l < y.l;
    return x.r < y.r;
}

void add(int current)
{
    cnt[a[current]]++;
    if(cnt[a[current]]==1)
        ANS++;
}

void reemove(int current)
{
    cnt[a[current]]--;
    if(cnt[a[current]]==0)
        ANS--;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];



    int Q;
    cin>>Q;
    int ans[Q];
    node q[Q];
    for(int i=0; i<Q; i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].i=i;
    }
    sort(q,q+Q,comp);

    int currentl=0,currentr=0;
    for(int i=0; i<Q; i++)
    {
        while(q[i].l > currentl)
        {
            reemove(currentl);
            currentl++;
        }

        while(q[i].l < currentl)
        {
            add(currentl-1);
            currentl--;
        }

        while(q[i].r >= currentr)
        {
            add(currentr);
            currentr++;
        }
        while(q[i].r+1 < currentr)
        {
            reemove(currentr-1);
            currentr--;
        }
        ans[q[i].i]=ANS;
    }

    for(int i=0; i<Q; i++)
        cout<<ans[i]<<"\n";
}
