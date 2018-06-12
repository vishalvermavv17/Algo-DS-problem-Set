#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,c,n;
    cin>>r>>c>>n;

    int a[r][c];
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }
    int tx,ty,bx,by;
    int sum=0;

    long long int fib[100];
    fib[0]=0;
    fib[1]=1;

    for(int i=2; i<60; i++)
        fib[i]=fib[i-1]+fib[i-2];

    while(n--)
    {
        sum=0;
        cin>>tx>>ty>>bx>>by;
        for(int i=tx; i<=bx; i++)
        {
            for(int j=ty; j<=by; j++)
            {
                sum=(sum+a[i][j])%50;
            }
        }

        cout<<fib[sum]<<"\n";

    }
}
