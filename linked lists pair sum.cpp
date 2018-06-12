#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* newnode(int n)
{
    struct node * ptr;
    struct node* t1= (struct node *) malloc(sizeof(struct node * ));
    cin>>t1->data;
    t1->next='\0';
    t1->prev='\0';
    ptr=t1;
    while(--n)
    {
        struct node* temp= (struct node *) malloc(sizeof(struct node * ));
        ptr->next=temp;
        temp->prev=ptr;
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

    while(t1->next)
    {
        t2=t1->next;
    }

    while(t1!=


}

