#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct trie
{
    trie* left;
    trie* right;
    int range;
    trie():left(NULL),right(NULL),range(0){}
};

struct node
{
    long int maxXor;
    int rangeL;
    int rangeR;
    node():maxXor(0),rangeL(0),rangeR(0){}
};
node res;

void insertTrie(long int x, trie* root, int pos)
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
    if(root->range==0)
        root->range=pos;
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
                 res.maxXor+=(1<<i);
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
                res.maxXor+=t;
                root=root->right;
            }
        }

    }
    res.rangeL=root->range;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    long int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    node ans;
    long int pre=0;
    trie* node=new trie();
    insertTrie(0, node, 1);
    for(int i=0; i< n; i++)
    {
        pre=pre^a[i];
        insertTrie(pre, node,i+2);
        res.maxXor=0;
        maxXor(pre, node);
        res.maxXor^=pre;
        if(ans.maxXor < res.maxXor || (ans.maxXor == res.maxXor && ans.rangeL >= res.rangeL))
        {
            res.rangeR=i+1;
            ans=res;
        }
    }
    cout<<ans.maxXor<<"\n"<<ans.rangeL<<" "<<ans.rangeR;

    return 0;
}


