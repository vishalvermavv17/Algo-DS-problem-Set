#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    int q,k;
    cin>>q;
    while(q--)
    {
        cin>>k;
       int i=0,j=n-1;
        while(i<j)
        {
            if(a[i]+a[j]==k)
                break;
            else if(a[i]+a[j]<k)
                i++;
            else
                j--;
        }
        if(i==j)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
