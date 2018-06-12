//*********Stack Implementation********

#include<stdio.h>
int push(int s[5],int top,int value)
{
    int max=5;
    if(top>max-1)
        return 0;
    else
    {
        s[top]=value;
        top=top+1;
        return 1;
    }
}
int pop(int s[5],int top)
{
    int v;
    if(top<=0)
        return 9999;
    else
    {
        top=top-1;
        v=s[top];
        return v;
    }
}
int main()
{
    int s[5],value,a,b,i,top=0;
    do{
        printf("1 for push and 2 for pop\n");
        scanf("%d",&i);
       switch(i){
        case 1 : scanf("%d",&value);
                 a=push(s,top,value);
                 if(!a)
                    printf("Stack Full\n");
                 else
                    printf("Success\n");
                    if(top>=0 &&top<5)
                    top=top+1;
                 break;
        case 2 : b=pop(s,top);
                 if(b==9999)
                    printf("Stack Empty\n");
                 else
                    printf("Element is %d\n",b);
                    if(top>0 && top<=5)
                    top=top-1;
    }}
        while(i==1||i==2);

    return 0;
}
