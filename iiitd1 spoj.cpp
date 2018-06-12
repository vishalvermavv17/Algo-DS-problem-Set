#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
ll x;
//fast input
void fastscan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
//void fastscan(long int &number){bool negative = false;register int c;number = 0;c = getchar();if (c>47 && c<58){e = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}

void fastscan(long int &number){bool negative = false;register int c;number = 0;c = getchar();if(c>47 && c < 58){number = number *10 + c - 48;x=1; c=getchar();}for (; (c>47 && c<58); c=getchar()){number = number *10 + c - 48;x=x*10;}if (negative)number *= -1;}
//output
void print_ld(ll n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    fastscan(t);
    while(t--)
    {
        register int c;
        c=getchar();

        if(c=='-')
        {
            long int n;
            fastscan(n);
            x=2*n+x;
            print_ld(x);

        }
        else
        {
            if(c>47 && c < 58)
            {
                putchar('1');
                c=getchar();
            }
            for(;c > 47 && c < 58; c=getchar())
                putchar('0');
        }
        putchar('\n');
    }

    return 0;
}


