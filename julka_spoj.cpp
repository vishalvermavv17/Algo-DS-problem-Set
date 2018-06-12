#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,len1,len2,carry,flag=0,t=10;
    char s[102],k[102];
    int ns[102],d[102];
    while(t--)
    {
    cin>>s>>k;
    len1=strlen(s);
    len2=strlen(k);
    carry=0;
    flag=0;
    //addition module
    for(i=1;len1>=i;i++)
    {
        if(len2-i>=0)
        {
            ns[len1-i+1]=s[len1-i]+k[len2-i]+carry-96;
            carry=ns[len1-i+1]/10;
            ns[len1-i+1]=ns[len1-i+1]%10;
        }
        else
        {
            ns[len1-i+1]=s[len1-i]+carry-48;
            carry=ns[len1-i+1]/10;
            ns[len1-i+1]=ns[len1-i+1]%10;
        }
    }
    if(carry)
        ns[0]=carry;
    else
        ns[0]=0;

    /*for(i=1;i<=len1;i++)
    {
        if(carry || i)
            cout<<ns[i];
    }*/
    carry=0;

    //dividision module
    for(i=0;i<=len1;i++)
    {
       d[i]=(ns[i]+carry)/2;
       carry=(ns[i]%2)*10;
    }

    for(i=1;i<=len1;i++)
    {
        if((d[i]>0 || flag==1 || i==len1))
        {
            cout<<d[i];
            flag=1;
        }
    }
    cout<<endl;

    //subtraction module
    carry=flag=0;
    for(i=0;i<len1;i++)
    {

        if(s[len1-1-i]-48-carry >= d[len1-i])
        {
            ns[len1-i]=s[len1-1-i]-d[len1-i]-48-carry;
            carry=0;
        }
        else
        {
            ns[len1-i]=s[len1-1-i]-d[len1-i]-38-carry;
            carry=1;
        }
    }
    for(i=1;i<=len1;i++)
    {
        if((ns[i]>0 || flag==1 || i==len1))
        {
            cout<<ns[i];
            flag=1;
        }
    }
    if(t)
    cout<<endl;
    }
    return 0;
}
