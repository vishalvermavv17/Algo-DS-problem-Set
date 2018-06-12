#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct node
    {
        int data;
        struct node *next;
    }start,*ptr,*nptr;

long int printnode(node* node, long int sum )
{
    if(!node)
        return 0;

    sum=node->data+printnode(node->next,sum);
    cout<<node->data;
    return sum;
}


int main()
{

    start.next='\0';
    ptr=(struct node *) malloc(sizeof(struct node));
    ptr->next='\0';
    scanf("%d",&ptr->data);
    start.next=ptr;
    fflush(stdin);
    printf("Enter 1 to add another node in lists");
    int i;
    scanf("%d",&i);
    while(i==1)
    {
         nptr=(struct node*)malloc(sizeof(struct node));
        nptr->next='\0';
        scanf("%d",&nptr->data);
        ptr->next=nptr;
        ptr=ptr->next;
        printf("Enter 1 for adding another node to list");
        scanf("%d",&i);
    }
    ptr=start.next;
    while(ptr)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    long int sum=0;
        sum=printnode(start.next,sum);
    cout<<sum;
}

