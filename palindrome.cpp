#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    struct node * next;
}*ptr,*nptr,*start,*pptr,*head2,*midnode,*next;

int main()
{
    std::ios::sync_with_stdio(false);
    long int n;
    int flag=1;
    cin>>n;
    start = (node*) new node*;
    start->next='\0';
    ptr=start;

    while(n--)
    {
        nptr = (node*) new node*;
        cin>>nptr->data;
        nptr->next='\0';
        ptr->next=nptr;
        ptr=nptr;

    }
    ptr=nptr=start;
    while(nptr && nptr->next )
    {
        ptr=ptr->next;
        nptr=nptr->next->next;
    }

        midnode=ptr;
        ptr=ptr->next;
        midnode->next='\0';
        nptr='\0';
    if(ptr)
    {
       nptr=ptr->next;
        ptr->next='\0';
    }
cout<<ptr->data;
ptr=start->next;
while(ptr)
{
    cout<<ptr->data;
    ptr=ptr->next;
}/*
    while(nptr)
    {
        next=nptr;
        nptr=nptr->next;
        next->next=ptr;
        ptr=next;
    }
    head2=ptr;
    ptr=start->next;
    nptr=head2;
    while(ptr && nptr)
    {
        if(ptr->data != nptr->data)
        {
            flag=0;
            cout<<'NO';
            break;
        }
    }
    if(flag)
        cout<<'YES';*/

    return 0;
}
