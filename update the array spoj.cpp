#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,l,r,value,n,u;
    cin>>t;
    while(t--)
    {
        cin>>n>>u;
        int input[n+1]={0};
        while(u--)
        {

            cin>>l>>r>>value;
                input[l]+=value;
                input[r+1]-=value;
        }
        for(l=1; l<n;l++)
            input[l]+=input[l-1];

        cin>>l;
        while(l--)
        {
            cin>>r;
            cout<<input[r]<<"\n";
        }
    }
}
