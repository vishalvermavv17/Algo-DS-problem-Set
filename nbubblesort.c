#include<stdio.h>

#define p printf
#define s scanf

void main()
{
    int a[5],i,j,min=1,temp;
    for(i=0;i<5;i++)
        s("%d",&a[i]);
    for(i=0;i<5 && min==1;i++)
    {
        min=0;
        for(j=0;j<4-i;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
            min=1;
        }
    }}
    for(i=0;i<5;i++)
        p("\n%d",a[i]);
}

