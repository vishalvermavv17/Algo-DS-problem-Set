#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x=2,y=3,idx=1;
    int a[150];
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1; j<=i; j++)
        {
            a[idx]=x*y;
            x+=2;  y+=4;    idx++;

        }
    }
    idx=1;  int col=n;
    for( i=1; i<=col;i++)
    {
        for( k=i;k<n;k++)
            printf(" ");

        for( j=1;j<=i;j++)
        {
            if(a[idx] <10)
                printf("0000");
            else if(a[idx] < 100)
                printf("000");
            else if(a[idx] < 1000)
                printf("00");
            else if(a[idx] < 10000)
                printf("0");

            printf("%d",a[idx]);
            idx++;
            if(j!=i)
                printf(" ");
        }
        if(i < n)
            printf("\n");
    }

    return 0;
}



