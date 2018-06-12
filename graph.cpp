#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <vector <int> > v(10);

    int n,m,i,j,snode;
    cin>>n>>m;

    while(m--)
    {
        int i,j;
        cin>>i>>j;
        v[i].push_back(j);
        v[j].push_back(i);
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=v[i].size();j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }

}
