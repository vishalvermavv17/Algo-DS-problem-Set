#include<stdio.h>
#define max 5
void main()
{
    int a[max][max],i,j,count=0,b[max][max];
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
            printf("%d\t",a[i][j]);

    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
            if(a[i][j]!= 0)
            {
                count++;
                b[count][0]=i;
                b[count][1]=j;
                b[count][2]=a[i][j];

            }
    }

    b[0][0]=i;
    b[0][1]=j;
    b[0][2]=count;

    for(i=0;i<=count;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
}
