#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000009
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    register int n,q,l,r;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int root=ceil(sqrt(n));

    int h[root];
    long int ans=MAX;
    for(int i=0; i<n; i++)
    {
        ans = ans < a[i] ? ans:a[i];
        if((i%root) == root-1)
        {
            h[(int)i/root]=ans;
            ans=MAX;
        }
    }

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        ans=MAX;
        for(int i=l; i<=r; i++)
        {
            if(!(i%root) && r >= (i+root-1))
            {
                ans=ans < h[(int)i/root] ? ans : h[(int)i/root];
                i+=root-1;
            }
            else
                ans= ans < a[i] ? ans : a[i];
        }
        cout<<ans<<"\n";
    }
}
