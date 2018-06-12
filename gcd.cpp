#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,b%a);
}

int main()
{
    int a=1,b=0,n;
    int ans;
    cin>>n;
    while(a<n)
    {
        ans=gcd(a,n);
        cout<<ans;
        if(ans==1)
            b++;
        a++;
    }
    cout<<b;
    return 0;
}
