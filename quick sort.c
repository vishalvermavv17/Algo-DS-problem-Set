#include <stdio.h>
long unsigned int a[100000];

void quicksort(long unsigned int low, long unsigned int high)
 {
   long unsigned int pivot, i, j, temp;
   if(low < high) {
     pivot = low;
     i = low+1;
     j = high;
     while(i <= j) {
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
int main()
{

    long unsigned int n,i;
    scanf("%lu",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(0,n-1);
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}
