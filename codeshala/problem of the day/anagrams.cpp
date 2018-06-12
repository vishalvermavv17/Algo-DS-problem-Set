#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin>>n;

    string s[50];
    for(int i=0; i<n; i++){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
    }

    map<string, long> m;
    for(int i=0; i<n; i++)
        m[s[i]]++;

    long cnt=0,tmp1;

    for(int i=0; i<n; i++){
        tmp1=m[s[i]];
        if(cnt < tmp1-1)
            cnt=tmp1;
    }
    cout<<cnt;
}
