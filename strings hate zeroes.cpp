#include"bits/stdc++.h"
using namespace std;

int query(int *st, int ql, int qh, int low, int high, long long int pos)
{
    if(ql > high || qh < low)
        return 0;
    if(ql <= low && qh >= high)
        return st[pos];
    int mid=(low+high)/2;
    return (query(st, ql, qh, low, mid, 2*pos+1)+query(st, ql, qh, mid+1, high, 2*pos+2));
}

void countZeroSegTree(char s[], int *st, int low, int high, long long int pos)
{
    if(low==high)
    {
        if((s[low]-48)==0)
            st[pos]=1;
        else
            st[pos]=0;
        return;
    }
    int mid=(low+high)/2;
    countZeroSegTree(s, st, low, mid, 2*pos+1);
    countZeroSegTree(s, st, mid+1, high, 2*pos+2);
    st[pos]=st[pos*2+1]+st[pos*2+2];
    return;
}

int * distinctNoSegTree(char s[100000], int *st, int low, int high, long long int pos)
{
    if(low==high)
    {
        st[pos]=1;
        int *h=new int[10];
        h[s[low]-48]=1;
        return h;
    }
    int mid=(low+high)/2;
    int *hl=new int[10];
    int *hr=new int[10];
    hl=distinctNoSegTree(s,st,low,mid,2*pos+1);
    hr=distinctNoSegTree(s,st,mid+1,high,2*pos+2);
    int i=0;
    int *h=new int[10];
    int ans=0;
    while(i<=9)
    {
        if(hl[i]==1 && hr[i]==1)
        {
            ans++;
            h[i]=1;
        }
        else if(hl[i]==1 || hr[i]==1)
            h[i]=1;

        i++;
    }

    st[pos]=st[2*pos+1]+st[2*pos+2]-ans;
    return h;
}


int main()
{
    char s[100000];
    cin>>s;

    int high=strlen(s);
    int low=0;

    int *rs = new int[(long long int)pow(2,ceil(log2(high-1)))*2-1];
    int *nZero=new int[(long long int)pow(2,ceil(log2(high-1)))*2-1];
    distinctNoSegTree(s, rs, low, high-1, 0);
    cout<<rs[0]<<rs[1]<<rs[2]<<rs[3]<<rs[4]<<"\n";

    countZeroSegTree(s, nZero, low, high-1, 0);
    cout<<nZero[0]<<nZero[1]<<nZero[2]<<nZero[3]<<nZero[4]<<"\n";

    long long int hcount=0;
    for(int i=0; i<high; i++)
    {
        for(int j=i; j<high; j++)
        {
            float x,y;
            x=(float)query(rs, i, j, low, high-1, 0);
            y=(float)query(nZero, i, j, low, high-1,0);

            if( (float)y < float(((j-i+1)/x)))
               hcount++;
            cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<(j-i+1)<<" "<<hcount<<"\n";
        }
    }
    cout<<"\n"<<hcount;
    return 0;
}
