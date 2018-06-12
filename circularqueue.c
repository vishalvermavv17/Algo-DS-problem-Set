#include<stdio.h>
#define max 3
#define p printf
#define s scanf


int f=0,r=0,flag=0;

void insert(int a[])
{
    int num;
    if(f==r && flag==1)
        p("\nStack Full");
    else
    {
        p("Enter the number to insert");
        s("%d",&num);
        a[r]=num;
        if(r+1==max)
            flag=1;
        r=(r+1)%max;
    }
}

int delete(int a[])
{
    int num;
    if(f==r && flag==0)
        p("Stack Empty");
    else
    {
        num=a[f];
        if(f+1==max)
            flag=0;
        f=(f+1)%max;
        p("%d",num);
    }

}

void main()
{
    int a[5],i,num,flag=0;
    do
    {
        p("\nPress 1 for insert     Press 2 for display     Press 3 for exit \n");
        s("%d",&i);
        switch(i)
        {
            case 1 : insert(a);
                     break;
            case 2 : num=delete(a);

                     break;
            default : break;
        }
    }while(i==1||i==2);
}
