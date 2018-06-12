#include<bits/stdc++.h>
using namespace std;

struct node{
    int l,r,i;
};

int a[50555],block=224,cnt[2]={0};

bool cmp(node x, node y)
{
    if(x.l/block != y.l/block)
        return x.l/block < y.l/block;

    return x.r < y.r;
}

void add(int pos)
{
    if(a[pos]==-1)
        cnt[0]++;
    else
        cnt[1]++;
}

void reemove(int pos)
{
    if(a[pos]==-1)
        cnt[0]--;
    else
        cnt[1]--;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i];

    node q[50555];
    for(int i=0; i<m; i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--; q[i].r--;
        q[i].i=i;
    }
    sort(q,q+m,cmp);
    int ans[55555];
    int currL=0,currR=0;
    for(int i=0; i<m; i++)
    {
        int ql=q[i].l,qr=q[i].r;
        while(ql < currL)
        {
            add(currL-1);
            currL--;
        }
        while(ql > currL)
        {
            reemove(currL);
            currL++;
        }
        while(qr > currR-1)
        {
            add(currR);
            currR++;
        }
        while(qr < currR-1)
        {
            reemove(currR-1);
            currR--;
        }
        ans[q[i].i]=min(cnt[0],cnt[1])*2;

    }
    for(int i=0; i<m; i++)
        cout<<ans[i]<<"\n";
    return 0;
}
