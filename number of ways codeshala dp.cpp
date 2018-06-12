#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;

    long long int nways[m];

    for(int i=0; i<m; i++)
        nways[i]=1;

    for(int i=1; i<n; i++)
        for(int j=1; j<m; j++)
            nways[j]=(nways[j]+nways[j-1])%1000000007;

    cout<<nways[m-1];
    return 0;
}

