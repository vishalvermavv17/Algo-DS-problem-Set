#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node{
    char tn[50];
    int gf;
    int ga;
    int gd;
    int pt;
};

bool comp(node x, node y)
{
    if(x.pt == y.pt)
    {
        if(x.gd == y.gd)
        {
            if(x.gf == y.gf)
            {
                if(strcmp(x.tn,y.tn) < 0)
                    return 1;
                return 0;
            }
            return x.gf > y.gf;
        }
        return x.gd > y.gd;
    }
    return x.pt > y.pt;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++)
    {
        for( int j=0; j<n; j++)
        {
            a[i][j]=0;
        }
    }
    node t[10009];
    map<string,int> m;
    for(int i=0; i<n; i++)
    {
        cin>>t[i].tn;
        m[t[i].tn]=i;
        t[i].gf=0;
        t[i].ga=0;
        t[i].gd=0;
        t[i].pt=0;
    }

    int q;
    cin>>q;
    char t1[50],t2[50];
    bool flag=0;
    int s1,s2;

    while(q--)
    {
        cin>>t1>>t2>>s1>>s2;
        a[m[t1]][m[t2]]++;  a[m[t2]][m[t1]]++;

        if(m[t1]==m[t2] || a[m[t2]][m[t1]] > 2 || a[m[t1]][m[t2]] > 2)
        {
            flag=1;
        }
        if(s1==s2)
        {
            t[m[t1]].pt+=1;
            t[m[t2]].pt+=1;
        }
        else if(s1<s2)
            t[m[t2]].pt+=2;
        else
            t[m[t1]].pt+=2;

        t[m[t1]].gf+=s1;
        t[m[t1]].ga+=s2;
        t[m[t1]].gd=t[m[t1]].gf - t[m[t1]].ga;

        t[m[t2]].gf+=s2;
        t[m[t2]].ga+=s1;
        t[m[t2]].gd=t[m[t2]].gf - t[m[t2]].ga;

    }
    if(flag)
    {
        cout<<"Invalid Input";
    }
    else
    {
        sort(t,t+n,comp);


        for( int i=0; i<n; i++)
        {
            cout<<t[i].tn;
            if(i<n-1)
                cout<<"\n";
        }
    }

    return 0;
}


