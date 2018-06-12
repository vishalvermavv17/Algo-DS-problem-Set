#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct trie
{
    trie *left;
    trie *right;
    bool isLeaf;
    trie():left(NULL),right(NULL),isLeaf(0){};
};


trie* insertTrie(trie* root, char s[])
{
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='.')
        {
            if(!root->left)
                root->left=new trie();
            root=root->left;
        }
        else
        {
            if(!root->right)
                root->right=new trie();
            root=root->right;
        }
    }
    return root;
}

long int query(trie *root, char p[], int level, int idx)
{
    if(!root || level==idx)
        return 0;
    trie* node=root;
    long int ans=0;
    for(int i=idx; i<level; i++)
    {
        if(p[i]=='.')
        {
            if(node->left)
            {
                node=node->left;
                if(i==level-1 && node->isLeaf)
                    return ++ans;
                if(node->isLeaf)
                    ans+=query(root, p, level, i+1);
            }
            else
                break;

        }
        else
        {
            if(node->right)
            {
                node=node->right;
                if(i==level-1 && node->isLeaf)
                    return ++ans;
                if(node->isLeaf)
                    ans+=query(root, p, level, i+1);
            }
            else
                break;

        }
    }
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    char md[26][20]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    int d;
    cin>>d;
    while(d--)
    {
        char pattern[1000];
        cin>>pattern;
        int n;
        cin>>n;
        trie* root=new trie();
        while(n--)
        {
            char s[20];
            cin>>s;
            int len=strlen(s);
            bool flag=0;
            trie* newNode=root;
            for(int i=0; i<len; i++)
            {

                if(i==len-1)
                    flag=1;
                newNode=insertTrie(newNode, md[s[i]-65]);
            }
            newNode->isLeaf=true;
        }

        int pattLen=strlen(pattern);
        cout<<query(root, pattern, pattLen, 0)<<"\n";
    }

    return 0;
}


