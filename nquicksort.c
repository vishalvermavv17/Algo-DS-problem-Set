#include<stdio.h>

#define p printf
#define s scanf

partition(int a[],int low,int high)
{
    int i,j,temp;
    int pivot=a[high];

    i=low-1;
    j=low;
    while(j<high)
    {
        if(a[j]<pivot)
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            j++;
        }
        else
            j++;
    }
    a[high]=a[i+1];
    a[i+1]=pivot;
    return i+1;


}

quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
       j=partition(a,low,high);
       p("\n%da",j);
       quicksort(a,low,j-1);
       quicksort(a,j+1,high);
    }

}

void main()
{
    int a[8],i,j,min,temp,low=0,high=7;
    for(i=0;i<8;i++)
        s("%d",&a[i]);
    quicksort(a,low,high);

    for(i=0;i<=high;i++)
        p("\n%d",a[i]);


}
