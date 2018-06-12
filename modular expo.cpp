#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a; long int b;
        cin>>a>>b;
        int ans=1,pow=a;
        while(b>0)
        {

            if(b%2)
                ans=ans*pow % 10;
            pow=pow*pow%10;
            b>>=1;
        }
        cout<<ans<<"\n";
    }
}
