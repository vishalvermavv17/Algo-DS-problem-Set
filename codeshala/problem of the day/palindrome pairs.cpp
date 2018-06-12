#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int i,len=s.length()-1;
    for(i=0; i<=len && s[i]==s[len]; i++,len--);
    return len<i;
}


int main()
{
    int n;
    cin>>n;

    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    string c;
    map<string,bool> m;
    for(int i=0; i<n; i++){
        c=s[i];

        reverse(c.begin(),c.end());
        cout<<c<<isPalindrome(c)<<"\n";
        m[c]=1;
    }

    int len,tmp=0,cnt=0;
    for(int i=0; i<n; i++){
        len=s[i].length();
        for(int j=0; j<len; j++){

            if(m[s[i].substr(0,len-j)]){
                c=s[i].substr(0,len-j);
                reverse(c.begin(),c.end());
                c=s[i]+c;
                cout<<c<<" ";
                if(isPalindrome(c))
                    tmp=c.length();
            }
        }
        if(tmp > cnt)
            cnt=tmp;
    }
    cout<<cnt;
}
