#include "bits/stdc++.h"
using namespace std;



int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    int mat[1000][1000];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    vector<unsigned long int> ans(1007);
    ans[0]=mat[0][0];
    for(int j=1; j<m; j++)
        ans[j]=mat[0][j]+ans[j-1];

    for(int i=1; i<n; i++)
        for(int j=0; j<m; j++){
            if(j == 0)
                ans[0]=ans[0]+mat[i][0];
            else
                ans[j]=( ans[j] < ans[j-1] ? ans[j] : ans[j-1]) + mat[i][j];
        }
    cout<<ans[m-1];

    return 0;
}
