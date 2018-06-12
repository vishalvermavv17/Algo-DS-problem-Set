#include <bits/stdc++.h>
using namespace std;
#define N 200009
#define A 1000009

struct node{
    int l,r,i;
};

long long int a[N],block,cnt[A]={0};
long long int power=0;
node q[A];

bool cmp(node x, node y)
{
    if(x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

void add(int i)
{
    /*power=power-(long long int) (cnt[a[pos]]*cnt[a[pos]]*a[pos]);
    cnt[a[pos]]++;
    power+=(long long int) (cnt[a[pos]]*cnt[a[pos]]*a[pos]);*/
    power += 2 * cnt[ a[i] ] * a[i] + a[i];
	cnt[ a[i] ]++;
}

void reemove(int i)
{
    /*power-=(long long int)(cnt[a[pos]]*cnt[a[pos]]*a[pos]);
    cnt[a[pos]]--;
    power+=(long long int) (cnt[a[pos]]*cnt[a[pos]]*a[pos]);*/
    cnt[ a[i] ]--;
	power -= 2 * cnt[ a[i] ] * a[i] + a[i];
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,Q;
    cin>>n>>Q;

    for(int i=0; i<n; i++)
        cin>>a[i];
    block=ceil(sqrt(n));
    long long int ans[Q];
    for(int i=0; i<Q; i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].i=i;
    }

    sort(q,q+Q,cmp);
    int currentL=0,currentR=0;
    for(int i=0; i<Q; i++)
    {
        int ql=q[i].l, qr=q[i].r;

        while( ql < currentL )
        {
            add(currentL-1);
            currentL--;
        }
        while(ql > currentL)
        {
            reemove(currentL);
            currentL++;
        }
        while(qr > currentR-1)
        {
            add(currentR);
            currentR++;
        }
        while(qr+1 < currentR)
        {
            reemove(currentR-1);
            currentR--;
        }
        ans[q[i].i]=power;
    }
    for(int i=0; i<Q; i++)
        cout<<ans[i]<<"\n";
}
