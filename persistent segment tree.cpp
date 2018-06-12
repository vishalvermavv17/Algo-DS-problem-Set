#include"bits/stdc++.h"
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* updatePersistentSegTree(node *Node, int ql, int value,int low, int high)
{
    if(low==ql && high==ql)
    {
        node* newNode= new node;
        newNode->data= Node->data+value;
        return newNode;
    }
    if(ql > high || ql < low)
        return Node;
    int mid=(low+high)/2;
    node* newNode= new node;
    newNode->left=updatePersistentSegTree(Node->left, ql, value, low, mid);
    newNode->right=updatePersistentSegTree(Node->right, ql, value, mid+1, high);
    newNode->data=min(newNode->left->data,newNode->right->data);
}


int rangeMinQuery(node *Node, int ql, int qh, int low, int high)
{
    if(ql > high || qh<low)
        return 100009;
    if(ql <= low && qh >= high)
        return Node->data;
    int mid  = (low+high)/2;
    return min(rangeMinQuery(Node->left,ql,qh,low,mid),rangeMinQuery(Node->right,ql,qh,mid+1,high));
}

void segTree(node *Node, int input[], int low, int high)
{
    if(low == high)
    {
        Node->data=input[low];
        return;
    }
    int mid=(low+high)/2;
    Node->left=new node;
    Node->right=new node;
    segTree(Node->left, input, low, mid);
    segTree(Node->right, input, mid+1, high);
    Node->data=min(Node->left->data, Node->right->data);
}


int main()
{
    int n;
    cin>>n;
    node *ver[100];
    int currVer=0;
    int input[n];
    for(int i=0; i<n; i++)
        cin>>input[i];

    node *root = new node;
    ver[0]=root;
    segTree(root, input, 0, n-1);

    cout<<root->data<<endl;
    int q;cin>>q;

    while(q--)
    {
        char qry;cin>>qry;
        int ql,qh;
        switch(qry)
        {
            case 'U' :  int value;
                        cin>>ql>>value;
                        ver[currVer+1]=updatePersistentSegTree(ver[currVer], ql-1, value, 0, n-1);
                        currVer++;
                        break;
            case 'Q' :  int v;
                        cin>>v>>ql>>qh;
                        cout<<rangeMinQuery(ver[v],ql-1,qh-1,0,n-1)<<"\n";
        }
    }
}
