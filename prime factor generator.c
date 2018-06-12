#include <stdio.h>

int main(void) {
	long unsigned int t,m,n,j,i,flag;
	scanf("%lu",&t);
	while(t--)
	{
		scanf("%lu%lu",&m,&n);

		for(i=m;i<=n;i++)
		{
			flag=1;
			for(j=1;j*j<=i&&flag==1;j++)
			{
				if(i%j==0)
					flag=0;
			}
			if(flag)
				printf("%lu\n",i);
		}
	}

	return 0;
}
