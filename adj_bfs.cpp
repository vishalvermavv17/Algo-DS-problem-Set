#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,visited[10]={0},count=0,t,flag=0;

    cin>>n>>m;
    int a[n][n]={0};

    while(m--)
    {
        int i,j;
        cin>>i>>j;
        a[i][j]=a[j][i]=1;
    }

    int node=1,b;
    //cout<<node<<" ";
    visited[node]=1;
    while(count!=n)
    {
        for(int i=1;i<=n;i++)
        {


            if(a[node][i] && !visited[i])
            {
                b=i;
                count++;
                cout<<i<<" ";
                visited[i]=1;
            }

        }
        node=b;
        if(visited[i])
            {
                flag=1;
                break;
            }
    }
   /* if(flag)
        cout<<"yes";
    else
        cout<<"no";
    cout<<endl;*/
    return 0;
}
