#include<stdio.h>
int a[5]={1,3,5,7,9},b[5]={2,4,6,8,10},c[10];
void merge(int low,int high)
{
    int i,j,k;
    i=low;
    j=low;
    k=low;
    while(i<=high && j<=high)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=b[j];
            j++;
        }
        k++;
    }
    if(i>high)
    {
        while(j<=high)
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=high)
        {
            c[k]=a[i];
            i++;
            k++;
        }
    }
}
void main()
{
    int i;
    merge(0,4);
    for(i=0;i<10;i++)
        printf("%d ",c[i]);
}

