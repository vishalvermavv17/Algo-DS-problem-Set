#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100000];
    char p[]=" !""#$%&'()*+0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_abcdefghijklmnopqrstuvwxyz{|}~";
    cin>>s;
    for(int i=0;i<26;i++)
    {
        int count=0;
        for(int j=0;s[j]!='\0';j++)
        {
            if(s[j]==p[i])
                count++;
        }
        if(count==1)
            cout<<p[i]<<" ";
    }

    return 0;
}
