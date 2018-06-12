#include<stdio.h>

#define p printf
#define s scanf

void main()
{
    int a[5],i,j,min,temp;
    for(i=0;i<5;i++)
        s("%d",&a[i]);
    for(i=0;i<4;i++)
        for(j=i+1;j<5;j++)
    {
        if(a[j]<a[i])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    for(i=0;i<5;i++)
        p("\n%d",a[i]);
}
