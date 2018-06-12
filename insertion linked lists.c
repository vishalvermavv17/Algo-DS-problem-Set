#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,value;
    struct node
    {
        int data;
        struct node *next;
    }start,*ptr,*nptr;
    /*start.next='\0';
    ptr=(struct node *) malloc(sizeof(struct node));
    ptr->next='\0';
    scanf("%d",&ptr->data);
    start.next=ptr;
    fflush(stdin);
    printf("Enter 1 to add another node in lists\t");
    int i;
    scanf("%d",&i);
    while(i==1)
    {
         nptr=(struct node*)malloc(sizeof(struct node));
        nptr->next='\0';
        scanf("%d",&nptr->data);
        ptr->next=nptr;
        ptr=ptr->next;
        printf("Enter 1 for adding another node to list\t");
        scanf("%d ",&i);
    }
    ptr=start.next;
    while(ptr)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }*/
    fflush(stdin);
    //nptr=(struct node *)malloc(sizeof(struct node));
    //nptr->data=5;
    start.next='\0';
    //nptr->next='\0';
    do
    {
            printf("Enter 1 for insert in the beginning\nEnter 2 for insert at the end\nEnter 3 for insert after some node\nEnter 4 to [rint linked lists\n");
            scanf("%d",&i);
            switch(i)
            {
                case 1: nptr=(struct node *)malloc(sizeof(struct node));
                        nptr->next=start.next;
                        start.next=nptr;
                        printf("Enter the value to be inserted\t");
                        scanf("%d",&nptr->data);
                        break;
                case 2: nptr=(struct node *)malloc(sizeof(struct node));
                        ptr=start.next;
                        while(ptr->next)
                            ptr=ptr->next;
                        ptr->next=nptr;
                        nptr->next='\0';
                        printf("Enter the value to be inserted\t");
                        scanf("%d",&nptr->data);
                        break;
                case 3: printf("Enter the value to be inserted\t");
                        scanf("%d",&value);
                        ptr=start.next;
                        nptr=ptr->next;
                        while(nptr->data<value)
                        {
                            ptr=ptr->next;
                            nptr=nptr->next;
                        }
                        nptr=(struct node *)malloc(sizeof(struct node));
                        nptr->next=ptr->next;
                        ptr->next=nptr;
                        nptr->data=value;
                        break;
                case 4: ptr=start.next;
                        while(ptr)
                        {
                            printf("%d",ptr->data);
                            ptr=ptr->next;
                        }
                }

    }while(i>0&&i<5);
}
