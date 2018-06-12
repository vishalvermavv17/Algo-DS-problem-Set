#include <stdio.h>
long unsigned int a[100000];

void quicksort(long unsigned int low, long unsigned int high)
 {
   long unsigned int pivot, i, j, temp;
   if(low < high) {
     pivot = low;
     i = low;
     j = high;
     while(i < j) {
       while(a[i] <= a[pivot] && i <= high)
         i++;
       while(a[j] > a[pivot] && j >= low)
         j--;
       if(i < j) {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
       }
     }
     temp = a[j];
     a[j] = a[pivot];
     a[pivot] = temp;
     quicksort(low, j-1);
     quicksort(j+1, high);
   }
}
/*int binsrch(long unsigned int a[100000],long unsigned int low,long unsigned int high,long unsigned int x)
{
    long unsigned int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        if(x==a[mid])
            return 1;
        else if(a[mid]<x)
            	low=mid+1;
        else if(a[mid]>x)
            high=mid-1;
    }
    else
        return 0;
}*/

int main()
{
    long unsigned int n,q,x,i;
    scanf("%lu%lu",&n,&q);
    long unsigned int flag;
    for(i=0;i<n;i++)
    	scanf("%lu",&a[i]);
    quicksort(0,n-1);
   /* while(q--)
    {
    	flag=0;
    	scanf("%lu",&x);
    	flag=binsrch(a,0,n,x);
    	if(flag)
    		printf("YES\n");
    	else
    		printf("NO\n");
    }*/
    for(i=0;i<n;i++)
        printf("%lu",a[i]);
    return 0;
}
