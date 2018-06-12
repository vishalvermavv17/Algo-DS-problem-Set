#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int d,ans;
    string s;
    cin>>d;

    stringstream ss;
    ss<< hex << d+d; // int decimal_value
    s = ss.str();
    ans=2*d;
    int len;
    map<char, int> m;
    int cnt;
    bool flag=0;

    while(!flag && s.size() < 8)
    {
        m.empty();
        cnt=0;
        len=s.length();
        for(int i=0; i<len; i++)
        {
            if(m[s[i]] == 0)
            {
                m[s[i]]++;
                cnt++;
            }
        }
        if(cnt < 3)
        {
            int i=0,j=len-1;
            while(s[i] == s[i+1])
                i++;
            while(s[j] == s[j-1])
                j--;
            if(j-i < 2)
                flag=1;
        }
        if(!flag)
        {
            stringstream ss;
            ss<< hex << ans+d; // int decimal_value
             s = ss.str();
             ans+=d;
        }

    }



    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'a' && s[i]<='z')
            s[i]=s[i]-32;
    }
    if(flag)
        cout<<s;
    else
        cout<<"NOTFOUND";




    return 0;
}
