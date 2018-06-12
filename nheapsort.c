#include<stdio.h>
#define p printf
#define s scanf

//Maintain heap on Insertion of new element
insert(int a[],int n)
{
    int temp,i;
    temp=a[n]; i=n;
    while(temp>a[i/2] && i>1)
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

void main()
{
    int a[8],i,j,min,temp,low=0,high=1;
    for(i=1;i<8;i++)
       {
           s("%d",&a[i]);

            insert(a,high);//insertion call every time when an element is added

            high=high+1;
       }
    for(i=1;i<high;i++)
        p("\n%d",a[i]);

}
