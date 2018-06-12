
#include<stdio.h>

int a[6];


void adjust( int i, int n)
{
    int temp,j;
    j=2i;
    temp=a[i];
    while(j<=n)
    {
    if(a[j]<a[j+1] && j<n)
        j=j+1;
    if(temp>a[j])
        break;
    a[j/2]=a[j];
    j=2j;
    }
    a[j/2]=temp;
}


void delmax( int i, int n)
{
    int temp;
    temp=a[n];  a[n]=a[1];  a[1]=temp;
    adjust(i,n-1);
}

void heapify(int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        adjust(i,n);
}

void heapsort(int n)
{
    int i;
    heapify(n);
    for(i=n;i>1;i--)
    {
        delmax(1,i);
    }
}

void main()
{
    int n;
    int a[6],i;
    a[0]=0;
n=5;
    for(i=1;i<6;i++)
        scanf("%d",&a[i]);

    heapsort(n);

    for(i=1;i<6;i++)
        printf("%d",a[i]);
}

