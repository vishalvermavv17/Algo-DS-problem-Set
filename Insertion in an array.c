#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,value,n=0,k,j,a[100];

    do
    {
            printf("Enter 1 for insert in the beginning\nEnter 2 for insert at the end\nEnter 3 for insert after some node\nEnter 4 to print array\n");
            scanf("%d",&k);
            switch(k)
            {
                case 1: printf("Enter the element");
                        scanf("%d",&value);
                        for(i=n;i>0;i++)
                            a[i+1]=a[i];
                        a[0]=value;
                        n++;
                        break;

                case 2: printf("Enter the element");
                        scanf("%d",&a[n]);
                        n++;
                        break;

                case 3: printf("Enter the element");
                        scanf("%d",&value);
                        j=0;

                        for(i=0;a[i]<value;i++)
                            a[i+1]=a[i];
                        a[i]=value;
                        n++;
                break;
                case 4: for(i=0;i<n;i++)
                            printf("%d\n",a[i]);

            }
    }while(k>0 && k<5);




}
