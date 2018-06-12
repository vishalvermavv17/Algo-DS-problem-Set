#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
char s[10];
struct trie
{
    map<char,trie*> m;
    bool isLeaf;
};

trie* getRoot()
{
    trie *newNode=new trie;
    newNode->isLeaf=false;
    return newNode;
}

bool insertNode(char s[], trie* root)
{
    int level;
    int len=strlen(s);
    for(level=0; level<len; level++)
    {
        if(!root->m[s[level]])
            root->m[s[level]]=getRoot();

        if(level!= len-1)
            if(root->m[s[level]]->isLeaf)
                return true;
        root=root->m[s[level]];

    }
    if(!root->isLeaf)
        for(int i=0; i<10; i++)
            if(root->m[i+48])
                return true;
    if(level==len)
        root->isLeaf=true;
    return false;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        trie* root=getRoot();
        bool flag=0;
        while(n--)
        {
            cin>>s;
            if(insertNode(s, root))
                flag=1;
        }
        if(flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }

    return 0;
}

