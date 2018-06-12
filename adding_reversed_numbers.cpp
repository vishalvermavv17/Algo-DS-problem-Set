#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    long int n,carry,sum,i,len1,len2,flag;
    char str1[10000],str2[10000];

    cin>>n;
    while(n--)
    {
        cin>>str1;
        cin>>str2;
        len1=strlen(str1);
        len2=strlen(str2);
        carry=flag=0;
        for(i=0;len1>i || len2>i;i++)
        {
            if(len1<i+1)
            {
                sum=str2[i]+carry-48;
                carry=sum/10;
                if(sum%10!=0 || flag )
                {
                    cout<<sum%10;
                    flag=1;
                }
            }
            else if(len2<i+1)
            {
                sum=str1[i]+carry-48;
                carry=sum/10;
                if(sum%10!=0 || flag )
                {
                    cout<<sum%10;
                    flag=1;
                }
            }
            else
            {
                sum=str1[i]+str2[i]+carry-96;
                carry=sum/10;
                if(sum%10!=0 || flag )
                {
                    cout<<sum%10;
                    flag=1;
                }
            }

        }
        if(carry)
            cout<<carry;
        cout<<"\n";
    }
    return 0;
}
