#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,value;
    struct doubly{
        int data;
        struct doubly *next;
        struct doubly *prv;
    }start,*nptr,*ptr;
    start.next='\0';
    start.prv='\0';
    ptr=&start;
    do
    {
      printf("Press 1 for add first node\nPress 2 to add last node\nPress 3 to add at some node\n");
      scanf("%d",&i);
      switch(i)
      {
          case 1:   nptr=(struct doubly *)malloc(sizeof(struct doubly));
                    scanf("%d",&nptr->data);
                    nptr->next=start.next;
                    start.next=nptr;
                    nptr->prv=&start;
                    ptr=start.next;
                    ptr->prv=nptr;
                    break;
          case 2:   ptr=start.next;
                    while(ptr)
                        ptr=ptr->next;
                    nptr=(struct doubly *) malloc(sizeof(struct doubly));
                    scanf("%d",&nptr->data);
                    ptr->next=nptr;
                    nptr->prv=ptr;
                    nptr->next='\0';
                    break;
          case 3:   scanf("%d",&value);
                    ptr=start.next;
                    while(ptr->data<value)
                        ptr=ptr->next;
                    nptr=(struct doubly *)malloc(sizeof(struct doubly));
                    nptr->data=value;
                    nptr->next=ptr;
                    nptr->prv=ptr->prv;
                    ptr->prv=nptr;
                    nptr->prv->next=nptr;
        }
    }while(i>0&&i<4);
    ptr=start.next;
    while(ptr)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
