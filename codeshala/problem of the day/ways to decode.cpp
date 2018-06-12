#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cnt[117];
    cin>>t;
    string s;
    cout<<t;
    while(t--){

        cin>>s;
        int n=s.length();
        cout<<n;
        cnt[0]=1;
        cnt[1]=1;
        for(int i=2; i<=n; i++){
            cnt[i]=0;

            if(s[i-1] > '0')
                cnt[i]=cnt[i-1];
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7'))
                cnt[i]+=cnt[i-2];
        }
        cout<<cnt[n]<<" "<<"\n";
    }

 return 0;
}
