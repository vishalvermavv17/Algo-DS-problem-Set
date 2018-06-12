#include<stdio.h>
int a[5],b[5];
void mergesort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low, int mid, int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
}
void main()
{
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(0,4);
    for(i=0;i<5;i++)
        printf("%d",b[i]);
}
