#include "bits/stdc++.h"
using namespace std;


//definition
#define gc() getchar()
#define pc() putchar()

#define MOD 1000000007
#define MAX 100005
#define pi 3.14159265358979
#define ESP (1e-9)
//definition
#define gc() getchar()
#define pc() putchar()
#define MOD 1000000007
#define MAX 100005
#define pi 3.14159265358979
#define ESP (1e-9)

typedef long int ld;
typedef long long int lld;
typedef unsigned long long int llu;

#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define fr(i,a) for(int i=0;i<a;i++)
#define fe(i,a) for(int i=0;i<=a;i++)

#define sf_d(n) scanf("%d",&n)
#define sf_ld(n) scanf("%ld",&n)
#define sf_lld(n) scanf("%lld",&n)


//fast input
void fastscan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
void fastscan(long int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
void fastscan(lld &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}

//end of fast input

//output
void print_d(int n) {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(lld n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n) {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n) {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}


int rangeMinQuery(int *st, int ql, int qh, int low, int high, long long int pos)
{
    if(ql <= low && high <= qh )
        return st[pos];
    else
        if(ql >high || qh < low)
            return -1;
    else
    {
        int mid=(low+high)/2;
        int x=min(rangeMinQuery( st, ql, qh, low, mid, 2*pos+1), rangeMinQuery(st, ql, qh, mid+1, high, 2*pos+2));
        int y=max(rangeMinQuery( st, ql, qh, low, mid, 2*pos+1), rangeMinQuery(st, ql, qh, mid+1, high, 2*pos+2));
        if(x==-1)
            return y;

        while(y%x)
        {
            int tmp=x;
            x=y%x;
            y=tmp;
        }
        return x;
    }

}


void constructTree( int input[], int *st, int low, int high,  lld pos)
{
    if(low==high)
    {
        st[pos]=input[low];
        return;
    }

    int mid=(low+high)/2;
    constructTree( input, st, low, mid, 2*pos+1 );
    constructTree( input, st, mid+1, high, 2*pos+2);
    //gcd
    int x=min(st[2*pos+1],st[2*pos+2]),y=max(st[2*pos+1],st[2*pos+2]);
    while(y%x)
    {
        int tmp=x;
        x=y%x;
        y=tmp;
    }
    st[pos]=x;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    sf_d(n);
    int input[n];
    fr(i,n)
        sf_d(input[i]);

    /*long int maxSize=(long int) pow(2,ceil(log2(n)))*2-1;

        int * st =  new int[maxSize];

        int  low=0, high=n-1;
        long long int pos=0;
        constructTree( input, st, low, high, pos );
*/
        lld sum=0;
        int gcd,x,y;
        fr(i,n)
        {
            gcd=i;
            sum+=i;
            for(int j=i+1; j<n; j++)
            {
                x=min(gcd, input[j]); y=max(gcd, input[j]);
                while(y%x)
                {
                    int tmp=x;
                    x=y%x;
                    y=tmp;
                }
                //sum+=rangeMinQuery(st, i, j, low, high, pos);
                sum+=x;
                gcd=x;


            }
        }
        print_lld(sum);

    return 0;
}


