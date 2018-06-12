
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    int n;
    cin>>n;
    int x=2,y=3,idx=1;
    float a[150];
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=i; j++)
        {
            a[idx]=x*y;
            x+=2;  y+=4;    idx++;

        }
    }
    idx=1;  int col=n;
    for(int i=1; i<=col;i++)
    {
        for(int k=i;k<n;k++)
            cout<<" ";

        for(int j=1;j<=i;j++)
        {
            if(a[idx] <10)
                cout<<"0000";
            else if(a[idx] < 100)
                cout<<"000";
            else if(a[idx] < 1000)
                cout<<"00";
            else if(a[idx] < 10000)
                cout<<"0";

            cout<<a[idx];
            if(j!=i)
                cout<<" ";
            idx++;
        }
        if(i < n)
            cout<<"\n";
    }

    return 0;
}


