#include<bits/stdc++.h>
#define maxweight mw
#define weight w
#define value v
using namespace std;

int main()
{
    int unsigned maxweight,n;
    cin>>mw>>n;
    int unsigned weight[n],value[n];
    for(int i=0;i<n;i++)
        cin>>v[i]>>w[i];
    unsigned int T[n+1][mw+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=mw;j++)
        {
            if(i==0 || j==0)
            {
                T[i][j]=0;
                continue;
            }
            if(weight[i-1]<=j)
                T[i][j]=max(T[i-1][j],value[i-1]+T[i-1][j-w[i-1]]);

            else
                T[i][j]=T[i-1][j];
        }
    }
    cout<<T[n][mw];

}
