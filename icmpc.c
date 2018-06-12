#include <stdio.h>
#include <string.h>

int main()
{
    int t,c,len,i,n,k,h[101];
    scanf("%d",&t);
    while(t--)
    {
    	for(i=0;i<101;i++)
    		h[i]=0;
    	scanf("%d%d",&n,&k);
    	char s[100];
    	for(i=0;i<n;i++)
    	{
    		scanf("%s",s);
    		len=strlen(s);
    		h[len]++;
    	}
    	n=0;
    	for(i=0;i<10;i++)
    	{
    	if((h[i]%k)==0 ||h[i]==0)
            n=1;
    	}
    	if(n==1)
    		printf("Possible\n");
    	else
    		printf("Not possible\n");
    }
    return 0;
}
