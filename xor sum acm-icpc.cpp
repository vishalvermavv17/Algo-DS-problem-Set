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


int res;

void insertTrie(long int x, trie* root)
{
    for(int i=31; i>=0; i--)
    {
        long int ans=x&(1<<i);
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

void maxXor(long int y, trie* root)
{
    for(int i=31; i>=0; i--)
    {
        long int t=y&(1<<i);
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        long int ans=0;
        long int pre=0;
        trie* node=new trie();
        insertTrie(0, node);
        for(int i=0; i< n; i++)
        {
            pre=pre^a[i];
            insertTrie(pre, node);
            res=0;
            maxXor(pre, node);
            ans=max(ans, res^pre);
        }
        cout<<ans<<"\n";


    }
    return 0;
}


