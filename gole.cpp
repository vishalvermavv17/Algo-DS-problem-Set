#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int j=t;
    while(j--)
    {
        int N,count,i,mul,n,h[10]={0};
        cin>>N;
        count=0;
        i=1;
        if(N==0)
            cout<<"Case #"<<t-j<<": "<<"INSOMNIA\n";
        else
        {
            while(count!=10)
            {
                mul=N*i;
                while(mul)
                {
                    n=mul%10;
                    mul=mul/10;
                    if(h[n]==0)
                    {
                        h[n]=1;
                        count++;
                    }
                }
                i++;
            }
        }
    if(count==10)
        cout<<"Case #"<<t-j<<": "<<N*(i-1)<<"\n";
    }
}
