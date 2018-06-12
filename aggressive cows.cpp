#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;


void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void fastscan(long int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void print_ld(ll n) {
    if(n<0)
    {
            n=-n;
            putchar('-');
    }
    int i=11;
    char output_buffer[11];
    do{
            output_buffer[--i]=(n%10)+'0';
            n/=10;
    }
    while(n);
    do{
            putchar(output_buffer[i]);
    }
    while(++i<11);
}


bool check(long int a[], long int mid, int n, int c)
{
    long int lastnode=a[0];
    int temp=1;
    for(int i=1; i<n; i++)
    {
        if(a[i]-lastnode >= mid)
         {
             ++temp;
             if(temp == c )
                return 1;
            lastnode=a[i];
         }
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    fastscan(t);
    while(t--)
    {
        int n,c;
        fastscan(n);
        fastscan(c);
        long int a[n];
        for(int i=0; i<n; i++)
            fastscan(a[i]);

        sort(a,a+n);

        long int low=0,mid;
        long int high=a[n-1]-a[0]+1;
        while(low<high)
        {
            mid=(low+high)>>1;
            if(check(a,mid,n,c)){
                low=mid+1;
            }
            else
                high=mid;
        }
        print_ld(low-1);
        putchar('\n');
    }

    return 0;
}
