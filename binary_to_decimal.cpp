#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int len1,i,sum=0,j=1,k=0,a[100],count=0,nsum;
    char s[100],c;
    cin>>s;
    len1=strlen(s);
    for(i=len1-1;i>=0;i--)
    {
        if(i!=len1-1)
            j=j*2;
        sum+=(s[i]-48)*j;
    }
    cout<<sum<<endl;



    nsum=sum;
    for(i=0;sum!=0;i++)
    {
        a[i]=sum%16;
        sum=sum/16;
        count++;
    }
    for(i=count-1;i>=0;i--)
    {
        if(a[i]>9)
        {
            c=55+a[i];
            cout<<c;
        }
        else
            cout<<a[i];
    }

    cout<<endl;
    count=0;
    sum=nsum;
    for(i=0;sum!=0;i++)
    {
        a[i]=sum%8;
        sum=sum/8;
        count++;
    }
    for(i=count-1;i>=0;i--)
        cout<<a[i];


}





