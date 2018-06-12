#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    map <string,int > word;
    char str[100000];
    int i;
    scanf("%[^\n]s",str);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>96)
            str[i]=str[i]-32;
        if(str[i]==' ')
        {
            word[s]++;
            s.clear();
        }
        else
            s+=str[i];
    }
    word[s]++;
    s.clear();
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            if(word[s]!=1001)
                cout<<s<<" "<<word[s]<<endl;
            word[s]=1001;
            s.clear();
        }
        else
           s+=str[i];
    }
    if(word[s]!=1001)
            cout<<s<<" "<<word[s];

    return 0;
}

