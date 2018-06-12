#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int i,len1,len2,carry;
    char s[100],k[100];
    int ns[100],d[100];
    cin>>s>>k;

    len1=strlen(s);
    len2=strlen(k);

    carry=0;
    for(i=0;i<len1;i++)
    {

        if(s[len1-1-i] >= d[len1-i])
        {
            ns[len1-i]=s[len1-1-i]-d[len1-i]-46-carry;
            carry=0;
        }
        else
        {
            ns[len1-i]=s[len1-1-i]-d[len1-i]-36-carry;
            carry=1;
        }
    }
    for(i=0;i<len1;i++)
        cout<<ns[i];
}
