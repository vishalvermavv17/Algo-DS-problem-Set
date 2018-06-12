#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct trie
{
    trie* left;
    trie* right;
    trie():left(NULL),right(NULL){}
};
int res=0;


void insertTrie(int x, trie* root)
{
    for(int i=5; i>=0; i--)
    {
        int ans=x&(1<<i);
        if(!ans)
        {
            if(root->left==NULL)
                root->left=new trie();
            root=root->left;
        }
        else
        {
            if(root->right==NULL)
                root->right=new trie();
            root=root->right;
        }
    }
}

void maxXor(int y, trie* root)
{
    for(int i=5; i>=0; i--)
    {
        int t=y&(1<<i);
        if(!t)
        {
            if(root->right)
            {
                 res+=(1<<i);
                 root=root->right;
            }
             else
                root=root->left;
        }
        else
        {
            if(root->left)
                root=root->left;
            else
            {
                res+=t;
                root=root->right;
            }
        }
    }
}



int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    trie* root=new trie();
    while(n--)
    {
        int x;
        cin>>x;

        insertTrie(x, root);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int y;
        cin>>y;
        res=0;
        maxXor(y, root);
        cout<<res<<endl;
    }
    return 0;
}


