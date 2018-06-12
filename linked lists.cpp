#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
     node* next;
};

struct node* newnode(int n)
{
    struct node * ptr;
    struct node* t1= ( node *) malloc(sizeof(struct node * ));
    cin>>t1->data;
    t1->next='\0';
    ptr=t1;
    while(--n)
    {
        struct node* temp= (struct node *) malloc(sizeof(struct node * ));
        ptr->next=temp;
         cin>>temp->data;
         temp->next='\0';
         ptr=temp;

    }
    return t1;
};

int main()
{
    struct node *ptr;
    int n,m;
    cin>>n;
        struct node*  t1=newnode(n);

    cin>>m;
        struct node*  t2=newnode(m);
    ptr->next=NULL;
    while(t1 && t2)
    {
        struct node * merge=(struct node *) malloc(sizeof(struct node *));
        if(t1->data >= t2->data)
        {
            merge->data=t2->data;
            merge->next='\0';
            cout<<t2->data;
            t2=t2->next;
        }
        else
        {
            cout<<t1->data;
            t1=t1->next;
        }
    }
    if(t1)
        while(t1)
        {
            cout<<t1->data<<" ";
            t1=t1->next;
        }
    else if(t2)
        while(t2)
        {
            cout<<t2->data<<" ";
            t2=t2->next;
        }


}
