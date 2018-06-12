#include <stdio.h>

int main()
{
    int n,i,temp,j,x;
    long unsigned a[200000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%lu",&a[i]);
    }
    for(i=1;i<n;i++)
    {
    	x=a[i];
    	for(j=i-1;j>=0 && x<a[j];j--)
    			a[j+1]=a[j];
        a[j+1]=x;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}
