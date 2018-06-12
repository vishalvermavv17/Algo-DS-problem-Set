#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long n;
    cin>>t;
    while(t--){
        cin>>n;

        string s;
        for(;n;n/=26){
            s.push_back(n%26);
            if(!(n%26))
                n--;
        }
        int len=s.length();
        char c;
        for(int i=len-1; i>=0;i--){
            if(s[i]==0)
                cout<<"Z";
            else{
                c='A'-1+s[i];
                cout<<c;
            }
        }
        cout<<"\n";
    }
}
