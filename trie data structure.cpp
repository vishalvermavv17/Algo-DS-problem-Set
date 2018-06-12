#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
char s[200007];
int top,cnt=0;
struct trie
{
    map<char,trie* >m;
    bool isLeaf;
};

trie* getRoot()
{
    trie *newNode=new trie;
    newNode->isLeaf=false;
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
        root=root->m[s[level]];

    }
}

void dfs(trie * root)
{

    for(char i='a'; i<='z'; i++)
    {
        if(root->m[i])
        {
            s[top]=i;
            top++;
            if(root->m[i]->isLeaf)
            {
                for(int i=0; i<top; i++)
                    cout<<s[i];
                cout<<"\n";
            }
            dfs(root->m[i]);
            top--;
        }

    }
}

void srchTrie(char s[], trie* root)
{
    int level=0;
    int len=strlen(s);
    for(int level=0; level<len; level++)
    {
        if(root->m[s[level]])
            root=root->m[s[level]];
        else
        {
            cout<<"No Suggestions\n";
            return;
        }
    }
    top=len;
    if(root->isLeaf)
        cout<<s<<"\n";
    dfs(root);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    trie* root=getRoot();
    while(n--)
    {
        cin>>s;
        int len=strlen(s);
        for(int i=0; i<len; i++)
            if(s[i]<'a')
                s[i]+=32;
        insertNode(s, root);
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>s;
        srchTrie(s, root);
        cout<<"\n";
    }

    return 0;
}
