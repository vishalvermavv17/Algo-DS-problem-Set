#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
char s[1000007];
int cnt=0;
struct trie
{
    map<char,trie* >m;
    bool isLeaf;
    int cnt;
};

trie* getRoot()
{
    trie *newNode=new trie;
    newNode->isLeaf=false;
    newNode->cnt=0;
    return newNode;
}

void insertNode(char s[], trie* root)
{
    int len=strlen(s);
    for(int level=0; level<len; level++)
    {
        if(!root->m[s[level]])
        {
            root->m[s[level]]=getRoot();
        }
        if(level==len-1)
                root->m[s[level]]->isLeaf=true;
        root->m[s[level]]->cnt+=1;
        root=root->m[s[level]];

    }
}

int srchTrie(char s[], trie* root)
{
    int len=strlen(s);
    for(int level=0; level<len; level++)
    {
        if(root->m[s[level]])
            root=root->m[s[level]];
        else
        {
            return 0;
        }
    }
    return root->cnt;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    trie* root=getRoot();
    while(n--)
    {
        cin>>s;
        int len=strlen(s);
        insertNode(s, root);
    }
    while(q--)
    {
        cin>>s;
        cnt=0;
        cout<<srchTrie(s, root)<<"\n";

    }

    return 0;
}

