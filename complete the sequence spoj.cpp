#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,c,flag=1;
        cin>>n>>c;
        int q=c;
        int a[n][n+c]={0};

        for(int i=0;i<n;i++)
            cin>>a[0][i];
        int ncount=0;
        for(int i=1; i<n && flag;i++)
        {
            ncount++;
            for(int j=0;j<n-i;j++)
            {
                a[i][j]=a[i-1][j+1]-a[i-1][j];
                if(j==0)
                    flag=0;
                else if(!flag && a[i][j-1]!=a[i][j])
                    flag=1;
            }
        }
        int row,column,j=-1;
        row=ncount; column=n-ncount;
        while(c--)
        {
            ++j;
            a[row][column+j]=a[row][column+j-1];
            for(int i=ncount-1; i>=0;i--)
                a[i][n-i+j]=a[i][n-i-1+j]+a[i+1][n-i-1+j];

        }

        for(int j=n;j<n+q;j++)
            cout<<a[0][j]<<" ";

        cout<<"\n";
    }
    return 0;
}
