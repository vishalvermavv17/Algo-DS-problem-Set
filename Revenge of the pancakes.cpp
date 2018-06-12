#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream myfile;
myfile. open ("output.txt");
    int t;
    cin>>t;
    int x=t;
    while(t--)
    {
        char s[103];
        cin>>s;
        int count=0;
        int len=strlen(s);
        for(int i=1;s[i];i++)
            if(s[i-1]!=s[i])
                count++;

        if(s[len-1]=='-')
            count++;

    myfile<<"Case #"<<x-t<<": "<<count<<"\n";

    }
    return 0;
}
