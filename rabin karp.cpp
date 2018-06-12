#include<bits/stdc++.h>
#define MOD 1e9+7
using namespace std;

int main()
{
    string s,p;
    cin>>s>>p;

    int hp=0;
    for(int i=0; p[i]!='\0'; i++)
        hp+=( (p[i]-96) * pow(26,i) )% MOD;


}
