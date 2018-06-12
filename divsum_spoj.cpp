#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long int t,n,sum,i;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum=sum+i;
                if(i*i!=n)
                    sum+=n/i;
            }
        }
        if(n==1)
            cout<<"0\n";
        else
            cout<<sum+1<<endl;
    }
    return 0;
}
