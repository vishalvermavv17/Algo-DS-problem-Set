#include <stdio.h>

int a[100];

binsrch(int value, int low, int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==value)
            return mid+1;
        else if(a[mid]<value)
            binsrch(value,mid+1,high);
        else
            binsrch(value,low,mid-1);


    }
    else
        return 0;
}

int main()
{
    int n,i,value,flag;

    printf("Enter the size of the array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter the value to be searched");
    scanf("%d",&value);
    flag=binsrch(value,0,n);

    if(flag)
        printf("Success at location %d",flag);
    else
        printf("Element not found");
}
