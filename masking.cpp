#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,nsum,c,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>n)
            c=a[i]-n;
        else
            c=a[i];
        if(a[c]>n )
            break;
        a[c]+=n;
    }
    nsum=(n*(n+1))/2;
    sum=nsum-sum+c;
    cout<<c<<" "<<sum;
}
