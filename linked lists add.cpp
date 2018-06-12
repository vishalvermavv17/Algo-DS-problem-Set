#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};


int main()
{
    struct node *ptr;
    struct node* t2;
    struct node* temp;

    int n,m;
    cin>>n;
        t2='\0';
    struct node* t1= (struct node *) malloc(sizeof(struct node * ));
    cin>>t1->data;
    ptr=t1;
     if(t1->data!=9)
            t2=t1;
    while(--n)
    {
        struct node* temp= (struct node *) malloc(sizeof(struct node * ));
        ptr->next=temp;
        temp->prev=ptr;
         cin>>temp->data;
         if(temp->data!=9)
            t2=temp;
         temp->next='\0';
         ptr=temp;

    }
    if(t2!='\0')
     {
         t2->data=t2->data+1;
         temp=t1;
        while(t2->next)
        {
            t2=t2->next;
            t2->data=0;
        }
     }
    else
    {
        struct node* t2= (struct node *) malloc(sizeof(struct node * ));
        t2->next=t1;
        t2->data=1;
    }

    while(temp)
    {
        cout<<temp->data;
        temp=temp->next;
    }

}


