#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    register int n,m,w;
    cin>>n>>m>>w;
    int a[w+1]={0};
    for(int i=0; i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        a[l]+=1;
        a[r+1]-=1;
    }
    for(int i=1; i<w; i++)
        a[i]+=a[i-1];


    while(m--)
    {
        cin>>n;
        cout<<a[n]<<"\n";
    }
}
