#include<stdio.h>

#define p printf
#define s scanf
int b[8];

merge(int a[], int low, int high)
{
    int i,j,k,b[high+1];
    int mid=(low+high)/2;
    i=low; j=mid+1; k=low;
    while(j<=high && i<=mid)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
        if(i>mid)
        {
            while(j<=high)
            {
                b[k]=a[j];
                k++;
                j++;
            }
        }
        else
        {
            while(i<=mid)
            {
                b[k]=a[i];
                k++;
                i++;
            }
        }


        for(i=low;i<=high;i++)
            a[i]=b[i];

}

mergesort(int a[],int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high);
    }

}

void main()
{
    int a[8],i,j,min,temp,low=0,high=7;
    for(i=0;i<8;i++)
        s("%d",&a[i]);

    mergesort(a,low,high);
    for(i=0;i<=high;i++)
            p("%d",a[i]);
}
