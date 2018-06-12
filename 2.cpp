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
        char s[25];
        cin>>s;
        int len=strlen(s);
        int l=len;
        for(int i=len-1;i>0;i--)
        {
            if(s[i]<s[i-1])
            {
                l=i;
                s[i-1]=s[i-1]-1;
            }
        }
        int flag=0;
        myfile<<"Case #"<<x-t<<": ";
        for(int i=0;i<l;i++)
        {

            if(s[i]!='0')
            {
                flag=1;
                myfile<<s[i];
            }
            else if(flag)
            {
                for(i=i;i<l;i++)
                {
                    myfile<<"9";
                }
            }
        }
        for(int i=l;i<len;i++)
        {
            myfile<<"9";
        }

        myfile<<"\n";
    }
}
