#include<stdio.h>

#define p printf
#define s scanf

//int quicksort(int *, int , int );

int partition(int a[], int low , int high)
{
    int temp,j=low;
    int i=low-1;  int pivot=a[high];
    while(j<high)
    {
        if(a[j]>=pivot)
            j++;
        else
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            j++;
        }

    }
        i++;
        temp=a[i];
        a[i]=pivot;
        a[high]=temp;

    return i;
}


int quicksort(int a[], int low, int high)
{
    int j;
    if(low<high)
    {
    j=partition(a,low,high);
    quicksort(a,low,j-1);
    quicksort(a,j+1,high);
    }
    return 0;
}


int main()
{
    int a[5],i;
    for(i=0;i<5;i++)
        s("%d",&a[i]);
    quicksort(a,0,4);

    for(i=0;i<5;i++)
        p("%d",a[i]);

    return 0;
}
