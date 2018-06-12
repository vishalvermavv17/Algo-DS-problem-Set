#include<iostream>
#include<bits/stdc++.h>
#define maxValue 10^9+1
using namespace std;


int lazyMinRangeQuery(int *st, int *lazy, int ql, int qh, int low, int high, int pos)
{
    if(lazy[pos]!=0)
    {
        st[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]=lazy[pos];
            lazy[2*pos+2]=lazy[pos];
        }
        lazy[pos]=0;
    }
    //no overlap
    if(ql>high || qh<low)
            return maxValue;

    //total Overlap
    if(ql <= low && qh >= high)
            return st[pos];

    //partial overlap
    int mid=(low+high)/2;
    return min(lazyMinRangeQuery(st, lazy, ql, qh, low, mid, 2*pos+1),
    lazyMinRangeQuery(st, lazy, ql, qh, mid+1, high, 2*pos+2));

}
void updateMinRangeSegTree(int* st, int *lazy, int ql, int qh, int delta, int low, int high, int pos)
{
    if(lazy[pos]!=0)//execute when update is required
    {
        st[pos]+=lazy[pos];
        if(low!=high)//if it is not a leaf node
        {
            lazy[2*pos+1]=lazy[pos];
            lazy[2*pos+2]=lazy[pos];
        }
        lazy[pos]=0;
    }

    //no overlap
    if(ql>high || qh<low)
    {
        return;
    }

    //total Overlap
    if(ql <= low && qh >= high)
    {
        st[pos]+=delta;
        if(low!=high)
        {
            lazy[2*pos+1]+=delta;
            lazy[2*pos+2]+=delta;
        }
        return;
    }

    //partial overlap
    int mid=(low+high)/2;
    updateMinRangeSegTree(st, lazy, ql, qh, delta, low, mid, 2*pos+1);
    updateMinRangeSegTree(st, lazy, ql, qh, delta, mid+1, high, 2*pos+2);
    st[pos]=min(st[2*pos+1],st[2*pos+2]);

}


void constructTree(int input[], int *st, int low, int high, int pos)
{
    if(low==high)
    {
        st[pos]=input[low];
        return;
    }

    int mid=(low+high)/2;
    constructTree(input, st, low, mid, 2*pos+1);
    constructTree(input, st, mid+1, high, 2*pos+2);
    st[pos]=min(st[2*pos+1],st[2*pos+2]);
}

int main()
{
    int n;
    cin>>n;

    int input[n];
    for(int i=0; i<n; i++)
        cin>>input[i];

    int maxSize=pow(2,ceil(log2(n)))*2-1;
    int *st =  new int[maxSize];
    int *lazy= new int[maxSize];
    for(int i=0; i<maxSize; i++)
    {
        lazy[i]=0;
        cout<<lazy[i]<<" ";
    }
    cout<<"\n";
    constructTree(input, st, 0, n-1, 0);
    for(int i=0; i<maxSize; i++)
            cout<<st[i]<<" ";

    int ql,qh,delta;
    int q;
    cin>>q;
    while(q--)
    {
        cin>>ql>>qh>>delta;
        updateMinRangeSegTree(st, lazy, ql,qh, delta, 0, n-1, 0);
        for(int i=0; i<maxSize; i++)
            cout<<st[i]<<" ";
        cout<<"\n";
        for(int i=0; i<maxSize; i++)
            cout<<lazy[i]<<" ";
    }
    cin>>ql>>qh;
    lazyMinRangeQuery(st, lazy, ql, qh, 0, n-1, 0);

    for(int i=0; i<maxSize; i++)
            cout<<st[i]<<" ";
        cout<<"\n";
        for(int i=0; i<maxSize; i++)
            cout<<lazy[i]<<" ";

}
