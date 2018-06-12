#include <iostream>
using namespace std;
int main()
{
    int n,h[2]={0},a[100],count,s[100],len=0,len1=0,i,j,k;
    cin>>n;

    for(0;i<n;i++)
    {
        cin>>a[i];
        h[a[i]]++;

    }
    if(h[0]>=h[i])
        j=h[1];
    else
        j=h[0];
    for(i=0;i<n-j;i++)
    {
        for(k=0;k<j;k++)
        {
            s[a[i]]++;
        }
        len=h[0]>h[1] ? 2*s[0]:2*s[1];
        if(len>len1)
            len1=len;
    }
    cout<<len1;

    for(int i=0;i<2;i++)
        cout<<h[i]<<" ";
}
