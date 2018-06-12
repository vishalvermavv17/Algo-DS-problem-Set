#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long int n,i,j;
    cin>>n;
    long int a[1000005];
    long int b[1000005];
    for( i=0;i<n;i++)
        cin>>a[i];

    long int m;
    cin>>m;
    for(i=0;i<m;i++)
        cin>>b[i];

     i=0;j=0;
    while(i+j<m+n)
    {
         if((a[i]<b[j] && i<n) || j==m)
         {
             cout<<a[i]<<" ";
             i++;
         }
         else if(j<m || i==n)
         {
             cout<<b[j]<<" ";
             j++;
         }
    }
return 0;
}

