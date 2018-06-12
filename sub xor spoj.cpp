#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct trie
{
    trie* left;
    trie* right;
    int rchild;
    int lchild;
    trie():left(NULL),right(NULL),rchild(0),lchild(0){};
};

void insertTrie(trie* root, int x)
{
    for(int i=19; i>=0; i--)
    {
        int pre=x&(1<<i);
        if(pre)
        {
            if(root->right==NULL)
                root->right=new trie();
            root->rchild++;
            root=root->right;
        }
        else
        {
            if(root->left==NULL)
                root->left=new trie();
            root->lchild++;
            root=root->left;
        }

    }
    return;
}

int query(trie* root, int pre, int k)
{
    if(root == NULL)
        return 0;
    long int res = 0;
    for(int i=19;i>=0;i--)
    {
        bool ch1=(k>>i) & 1;
        bool ch2=(pre>>i) & 1;
        if(ch1)
        {
            if(ch2){
                res+=root->rchild;
                if(root->left == NULL)
                    return res;
                root = root->left;
            }

            else{
                res+=root->lchild;
                if(root->right == NULL)
                    return res;
                root = root->right;
            }
        }
        else
        {
            if(ch2){
                if(root->right == NULL)
                    return res;
                root= root->right;
            }
            else{
                if(root->left == NULL)
                    return res;
                root= root->left;
            }
        }
    }
    return res;
}




/*{
    if(root==NULL || level==-1)
        return 0;
    int p=pre&(1<<level);
    int q=k&(1<<level);
    if(q)
    {
        if(p==0)
            return(root->lchild+query(root->right, pre, k, level-1));


        else
            return(root->rchild+query(root->left, pre, k, level-1));

    }
    else
    {
        if(p==1)
            return(query(root->right, pre, k, level-1));

        else
            return(query(root->left, pre, k, level-1));
    }
}*/

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];
        long int ans=0;
        trie* root=new trie();
        insertTrie(root, 0);
        int pre=0;
        for(int i=0; i<n; i++)
        {
            pre=pre^a[i];
            ans+=query(root, pre, k);
            insertTrie(root, pre);
        }
        cout<<ans<<"\n";
    }

    return 0;
}

