#include<stdio.h>



typedef long long int lld;

#define sf_lld(n) scanf("%lld",&n)




//output
void print_lld(lld n) {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

int main()
{

    lld t,n,i=9223372036854775807;
    sf_lld(t);
    while(t--)
    {
            sf_lld(n);

            n>>=1;
            n=n&i;
            print_lld(n);
            putchar('\n');
    }

    return 0;
}



