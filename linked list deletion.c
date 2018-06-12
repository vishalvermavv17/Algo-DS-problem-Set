#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,value;
    struct node
    {
        int data;
        struct node *next;
    }start,*ptr,*nptr,*top;
    start.next='\0';
    ptr=(struct node *) malloc(sizeof(struct node));
    ptr->next='\0';
    scanf("%d",&ptr->data);
    start.next=ptr;
    fflush(stdin);
    printf("Enter 1 to add another node in lists");
    scanf("%d",&i);
    while(i==1)
    {
         nptr=(struct node*)malloc(sizeof(struct node));
        nptr->next=0;
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
    do
    {
        printf("Press 1 for delete from beginning\nPress 2 for delete at the end\nPress 3 for delete from certain node\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1 :ptr=start.next;
                    start.next=ptr->next;
                    free(ptr);
                    break;
            case 2 :ptr=start.next;
                    nptr=ptr->next;
                    while(nptr)
                    {
                        ptr=ptr->next;
                        nptr=nptr->next;
                    }
                    ptr->next=0;
                    free(nptr);
                    break;
            case 3 :printf("Enter value to be deleted");
                    scanf("%d",&value);
                    ptr=&start;
                    nptr=start.next;
                    while(nptr->data!=value)
                    {
                        ptr=ptr->next;
                        nptr=nptr->next;
                    }
                    ptr->next=nptr->next;
                    free(nptr);
        }
        ptr=start.next;
        while(ptr)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    }while(i>0&&i<4);

    return 0;
}
