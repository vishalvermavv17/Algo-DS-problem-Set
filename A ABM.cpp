#include <bits/stdc++.h>
using namespace std;


long long int f( int x)
{
    int ans=max(x,1);
    return ans*ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,b;
        cin>>n>>b;
        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        int Max=0;

        if(n%2)
        {
            for(int i=0; i<n;i++)
            {
                if(i <= n/2)
                    Max=max(Max, a[i]+n/2-i);
                else
                    Max=max(Max, a[i]-n/2+i);
            }
        }
        else
        {
            for(int i=0; i<n;i++)
            {
                if(i <n/2)
                    Max=max(Max, a[i]+n/2-i-1);
                else
                    Max=max(Max, a[i]-n/2+i);
            }
        }

        // Cal price
        long long int sum=0;
        int ih,bp;

        if(n%2)
        {

            for(int i=0; i<n; i++)
            {

                if(i<=n/2)
                {
                    ih=Max-a[i]-n/2+i;
                    bp=b;

                    for(int i=0; i<ih; i++ )
                    {
                        sum+=f(bp);
                        bp--;
                    }

                }
                else
                {
                    ih=Max-a[i]+n/2-i;
                    bp=b;

                    for(int i=0; i<ih; i++ )
                    {
                        sum+=f(bp);
                        bp--;
                    }

                }
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(i<n/2)
                {
                    ih=Max-a[i]-n/2+i+1;
                    bp=b;

                    for(int i=0; i<ih; i++ )
                    {
                        sum+=f(bp);
                        bp--;
                    }

                }
                else
                {
                    ih=Max-a[i]+n/2-i;
                    bp=b;

                    for(int i=0; i<ih; i++ )
                    {
                        sum+=f(bp);
                        bp--;
                    }

                }
            }
        }
        cout<<sum*1000<<"\n";

    }
}
