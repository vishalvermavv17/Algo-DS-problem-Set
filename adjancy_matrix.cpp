#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][n]={0};

    while(m--)
    {
        int i,j;
        cin>>i>>j;
        a[i-1][j-1]=a[j-1][i-1]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i][j]==1)
                cout<<a[i][j]<<" ";
            else
                cout<<"0"<<" ";
        cout<<endl;
    }
    return 0;
}
