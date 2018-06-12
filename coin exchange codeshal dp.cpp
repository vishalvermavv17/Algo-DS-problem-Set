#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);

    int s,n,minCoin[10007],coinVal[10000];

    cin>>n>>s;
    for(int i=0; i<n; i++)
        cin>>coinVal[i];

    sort(coinVal,coinVal+n);

    minCoin[0]=0;
    for(int i=1; i<=s; i++)
        minCoin[i]=s+1;

    for(int i=0; i<n; i++)
        for(int j=coinVal[i]; j<=s; j++)
            if(minCoin[j-coinVal[i]]+1 < minCoin[j] )
                minCoin[j]=minCoin[j-coinVal[i]]+1;

    if(minCoin[s] <= s)
        cout<<minCoin[s];
    else
        cout<<"-1";

    return 0;
}

