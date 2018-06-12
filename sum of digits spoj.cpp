#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        char a[100];
        scanf("%s[^\n]",a);

        int sum=0;
        for(int i=0;a[i]!='\0';i++)
            sum+=a[i]-48;

        cout<<sum<<"\n";
    }
}
