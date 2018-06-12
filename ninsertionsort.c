#include<stdio.h>

#define p printf
#define s scanf

void main()
{
    int a[5],i,j,min,temp;
    for(i=0;i<5;i++)
        s("%d",&a[i]);
    for(i=1;i<5;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--)
    {

            a[j+1]=a[j];

    }
    a[j+1]=temp;
    }
    for(i=0;i<5;i++)
        p("\n%d",a[i]);
}

