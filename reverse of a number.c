#include <stdio.h>

int main()
{
    int n,temp;
    printf("Enter the number:\t");
    scanf("%d",&n);

    while(n!=0)
    {
        temp=n%10;
        printf("%d",temp);
        n=n/10;
    }
    return 0;
}
