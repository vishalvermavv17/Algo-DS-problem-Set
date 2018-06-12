#include <iostream>
#include <bits/stdc++.h
using namespace std;
int main()
{
    int n,j=1,i,count=0,k,a[100];
    cin>>n;
    k=n;
    for(i=0;k!=0;i++)
    {
        a[i]=k%2;
        k=k/2;
        count++;
    }
    for(i=count-1;i>=0;i--)
        cout<<a[i];


}
