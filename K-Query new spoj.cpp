#include"bits/stdc++.h"
using namespace std;

struct node{
    long long int val;
    int i;
};

struct qnode{
    int l;
    int r;
    long long int k;
    int i;
};

bool comp(node x, node y)
{
    return x.val < y.val;
}

bool cmp(qnode x, qnode y){
    return x.k > y.k;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    node a[n+1];

    a[0].val=0;
    a[0].i=-1;


    int ft[n+1]={0};//fenwick tree
    for(int i=1; i<=n; i++)
    {
       cin>>a[i].val;
       a[i].i=i;
    }

    sort(a+1,a+n+1,comp);

    int qry;
    cin>>qry;
    qnode q[qry];
    for(int i=0; i<qry; i++)
    {
        cin>>q[i].l>>q[i].r>>q[i].k;
        q[i].i=i;
    }
    sort(q,q+qry,cmp);

    int ans[qry];
    int pos=n;
    for(int i=0; i<qry; i++)
    {
        int low=1, high=n,mid,flag=0;
        while(low <= high )
        {
            mid=(low+high)/2;
            if(a[mid-1].val <= q[i].k && a[mid].val > q[i].k)
                break;
            else
                if(a[mid].val <= q[i].k)
                    low=mid+1;
            else
                high=mid-1;
        }
        if(low<=high)
        {
            for(int j=mid; j<=pos; j++)
            {
                ft[a[j].i]+=1;
                int idx=a[j].i+(a[j].i & -a[j].i);
                while(idx <= n)
                {
                    ft[idx]+=1;
                    idx+=(idx&-idx);
                }
            }
            pos=mid-1;
        }

        int sum,diff;
        sum=ft[q[i].r];
        int idx=q[i].r-(q[i].r & -q[i].r);
        while(idx > 0)
        {
            sum+=ft[idx];
            idx-=(idx&-idx);
        }

        diff=ft[q[i].l-1];
        idx=(q[i].l-1)-((q[i].l-1)&-(q[i].l-1));
        while(idx > 0)
        {
            diff+=ft[idx];
            idx-=(idx & -idx);
        }
        ans[q[i].i]=sum-diff;
    }

    for(int i=0; i<qry; i++)
        cout<<ans[i]<<"\n";
    return 0;
}
