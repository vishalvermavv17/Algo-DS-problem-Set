#include<stdio.h>

#define p printf
#define s scanf

void main()
{
    int a[5],i,flag,low=0,high=4,mid,value;

    for(i=0;i<5;i++)
        s("%d",&a[i]);
        s("%d",&value);

    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==value)
        {
            p("\nsuccess at %d",mid+1);
            break;
        }
        else if(a[mid]>value)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}
