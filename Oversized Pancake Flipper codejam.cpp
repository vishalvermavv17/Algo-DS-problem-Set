#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream myfile;
    myfile. open ("1LzongOutput.txt");

    int t;
    cin>>t;
    int x=t;
    while(t--)
    {
        char s[1005];
        cin>>s;
        int k,flip=0,len,flag=1;
        len=strlen(s);
        cin>>k;
        for(int i=0;s[i] && flag;i++)
        {
            if(s[i]=='-')
            {
                flip++;
                int cont=1;
                for(int j=i;j<len && cont<=k;j++)
                {

                    if(s[j]=='-')
                        s[j]='+';
                    else
                        s[j]='-';

                    cont++;
                }
                if(cont<=k)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Case #"<<x-t<<": "<<flip<<"\n";
        else
            cout<<"Case #"<<x-t<<": "<<"IMPOSSIBLE\n";

    }

return 0;
}
