#include <stdio.h>

int main()
{
    int a[200],i,j,m,temp,k,n,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);
    a[0]=1;
    m=1;

    for(i=2;i<=n;i++)
    {
        temp=0;
        for(j=0;j<m;j++)
        {
            k=a[j]*i+temp;
            a[j]=k%10;
            temp=k/10;
        }
            while(temp>0){
            a[m]=temp%10;
            temp=temp/10;
            m++;}

    }
    for(i=m-1;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");
    }
    return 0;

}
