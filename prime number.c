#include <stdio.h>

int main()
{
    int n,i,temp,j,k,flag=0;
    long unsigned a[200000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%lu",&a[i]);
    }
    for(i=1;i<n-1;i++)
    {
    	k=a[i];
    	flag=0;
    	for(j=i-1;j>=0&&flag==0;j--)
    	{
    		if(a[j]>k)
    		{
    			temp=a[j+1];
    			a[j+1]=a[j];
    		}
    		else
                flag=1;

    	}
    	a[i]=temp;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}
