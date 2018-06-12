#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool a[n+1]={};
    a[1]=true;
    for(int i=2;i*i<=n;i++)
    {
        if(!a[i])
        {
            for(int j=2*i;j<=n;j+=i)
            {
                a[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
     {

       if(!a[i])
            cout<<i<<",";
     }
}
