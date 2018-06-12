#include"bits/stdc++.h"
using namespace std;

struct node{
    long long int data;
    node *left;
    node *right;
};


int kQuery(node * Node, int ql, int qh, int low, int high)
{
    if(ql > high || qh < low)
        return 0;

    if(ql <= low && qh >= high)
        return Node->data;

    int mid=(low+high)>>1;
    return(kQuery(Node->left, ql, qh, low, mid)+kQuery(Node->right, ql, qh, mid+1, high));
}

node* updateSegTree(node *prevNode, int ql, long long int x, int low, int high)
{
    if(low==ql && high==ql)
    {
        node* newNode = new node;
        newNode->data=0;
        return newNode;
    }
    if(ql > high || ql < low)
        return prevNode;
    int mid=(low+high)>>1;
    node * newNode=new node;
    newNode->left=updateSegTree(prevNode->left, ql, x, low, mid);
    newNode->right=updateSegTree(prevNode->right, ql, x, mid+1, high);
    newNode->data=newNode->left->data+newNode->right->data;
    return newNode;
}


void segTree(long long int input[], node *Node, long long int x, int low, int high)
{
    if(low == high )
    {
        if(input[low] > x)
            Node->data=1;
        else
            Node->data=0;
        return ;
    }
    int mid=(low+high)>>1;
    Node->left=new node;
    Node->right=new node;
    segTree(input, Node->left, x, low, mid);
    segTree(input, Node->right, x, mid+1, high);
    Node->data=Node->left->data+Node->right->data;
    return ;
}

int main()
{
    std::ios_base::sync_with_stdio(0);

    int n;
    scanf("%d%",&n);
    long long int input[n],a[n];
    for(int i=0; i<n ; i++)
    {
        scanf("%lld",&input[i]);
        a[i]=input[i];
    }

    map <long long int,stack<int> > m;
    for(int i=0; i<n; i++)
        m[input[i]].push(i);
    sort(a,a+n);

    node *ver[30009];
    node *root = new node;

    ver[0]=root;
    segTree(input, root, a[0], 0, n-1);
    m[a[0]].pop();

    for(int i=1; i<n; i++)
    {
        ver[i]=updateSegTree(ver[i-1], m[a[i]].top(), a[i], 0, n-1);
        m[a[i]].pop();
    }

    for(int i=n-1; i>=0; i--)
        if(a[i-1]==a[i])
            ver[i-1]=ver[i];


    long int q;
    scanf("%ld",&q);
    while(q--)
    {
        long int ql,qh,k;
        scanf("%ld%ld%ld",&ql,&qh,&k);
        int low=0,high=n-1;
        while(low!=high)
        {
            int mid=(low+high)>>1;
            if(a[mid]<=k)
                low=mid+1;
            else
                high=mid;

        }
        if(k < a[low] )
            low-=1;
        if(low==-1)
            printf("%ld\n",qh-ql+1);
            //cout<<qh-ql+1<<"\n";
        else if(k >= a[n-1])
            printf("0\n");
            //cout<<0<<"\n";
        else
            printf("%d\n",kQuery(ver[low], ql-1, qh-1, 0, n-1));
            //cout<<kQuery(ver[low], ql-1, qh-1, 0, n-1)<<"\n";
    }
    return 0;
}
