#include <bits/stdc++.h>
using namespace std;

/*void segTree(long long int a[], long long int *st, int low, int high, long long int pos)
{
    if(low==high)
    {
        st[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    segTree(a, st, low, mid, 2*pos+1);
    segTree(a, st, mid+1, high, 2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}

void update(long long int *st, int i, long long int x, int low, int high, long long int pos)
{
    if(i == low && i == high)
    {
        st[pos]=x;
        return;
    }
    if(i > high || i < low)
        return ;

    int mid=(low+high)/2;
    update(st, i, x, low, mid, 2*pos+1);
    update(st, i, x, mid+1, high, 2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
    return;
}

long long int querySegTree(long long int *st, int ql, int qh, int low, int high, long long int pos)
{
    if(ql > high || qh < low)
        return 0;
    if(ql <= low && qh >= high)
        return st[pos];
    int mid=(low+high)/2;
    return (querySegTree(st, ql, qh, low, mid, 2*pos+1)+querySegTree(st, ql, qh, mid+1, high, 2*pos+2));

}


int main()
{
    int n,q;
    cin>>n>>q;

    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    long long int *st= new long long int[ (int) pow(2,ceil(log2(n)))*2-1 ];
    segTree(a, st, 0, n-1, 0);

    int O;
    while(q--)
    {
        long long int sum=0;
        cin>>O;
        switch(O)
        {
            case 2 :    int i;
                        long long int x;
                        cin>>i>>x;
                        update(st, i-1, x, 0, n-1, 0);
                        break;
            case 1 :    int l,r,k;
                        cin>>l>>r>>k;
                        for(int j=l-1; j<r;j++)
                        {
                            int ql=j-k;
                            if(ql < 0)
                                ql=0;
                            sum+=querySegTree(st, ql, j, 0, n-1, 0);

                        }
                        cout<<sum<<endl;
        }
    }
    return 0;
}*/

int main()
{
    int n,q;
    cin>>n>>q;
    long long int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    long long int ft[n+1]={0};
    ft[0]=0;
    for(int i=0;i<n;i++)
    {
        ft[i+1]+=a[i];
        int idx=(i+1)+((i+1)&-(i+1));
        while(idx < n+1)
        {
            ft[idx]+=a[i];
            idx+=(idx&-idx);
        }
    }
    while(q--)
    {
        int o;
        cin>>o;
        switch(o)
        {
            case 1 :    int l,r,k;
                        cin>>l>>r>>k;
                        {
                            long long int ans=0;
                        for(int j=l-1; j<r; j++)
                        {
                            int pos=j-k;
                            if(pos <0)
                                pos=0;
                            long long int sum=0;
                            sum=ft[j+1];
                            int idx=(j+1)-((j+1)&-(j+1));
                            while(idx > 0)
                            {
                                sum+=ft[idx];
                                idx-=(idx&-idx);
                            }
                            long long int diff=ft[pos];
                            idx=pos-(pos&-pos);
                            while(idx>0)
                            {
                                diff+=ft[idx];
                                idx-=(idx&-idx);
                            }
                            ans+=sum-diff;
                        }
                        cout<<ans<<"\n";
                        }
                        break;

            case 2 :    int i;
                        long long int x;
                        cin>>i>>x;
                        ft[i]+=x-a[i-1];
                        int idx=i+(i&-i);
                        while(idx < n+1)
                        {
                            ft[idx]+=x-a[i];
                            idx=idx+(idx&-idx);
                        }
                        a[i-1]=x;
        }
    }
}
