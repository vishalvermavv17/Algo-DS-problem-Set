#include<stdio.h>

#define p printf
#define s scanf

bin(int a[], int low, int high, int value)
{
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(a[mid]==value)
            return mid+1;
        else if(a[mid]<value)
            bin(a,mid+1,high,value);
        else
            bin(a,low,mid-1,value);
    }
    else
        return -1;
}

void main()
{

    int a[5],low=0,high=4,i,value,r;
    for(i=0;i<5;i++)
        s("%d",&a[i]);
    s("%d",&value);
    r=bin(a,low,high,value);
    if(r>-1)
        p("success at %d",r);
}
