#include <iostream>
using namespace std;

struct node{
        int data;
        node * left;
        node * right;
    };

node * newNode(int value)
{
    node* root=new(node);
    root->data=value;
    root->left='\0';
    root->right='\0';
    return root;
}

node * insertNode(node * root, int value)
{
    if(!root)
        return(newNode(value));
    else
        if(root->data > value)
            root->left=insertNode(root->left,value);
    else
        if(root->data <= value)
            root->right=insertNode(root->right,value);


    return(root);
}


void InOrder(node* root)
{
    if(!root)
        return;

    InOrder(root->left);
    cout<<" "<<root->data;
    InOrder(root->right);
}

void PreOrder(node* root)
{
    if(!root)
        return;

    cout<<" "<<root->data;
    PreOrder(root->left);

    PreOrder(root->right);
}


void PostOrder(node* root)
{
    if(!root)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<" "<<root->data;
}

int main()
{
    node *root,*ptr;

    root='\0';
    int n,value;
    cin>>n;
    while(n--)
    {
        cin>>value;
        root=insertNode(root,value);
    }
    cout<<"Pre order :";
    PreOrder(root);
    cout<<"\nIn order  :";
    InOrder(root);
    cout<<"\nPost order:";
    PostOrder(root);
}
