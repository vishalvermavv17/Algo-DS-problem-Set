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

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,n,a,cnt;
    sf_d(t);
    lld fact[21];

    fact[0]=0;
    fact[1]=1;
    for(int i=2; i<21; i++)
        fact[i]=fact[i-1]*i;


    bool visited[21];
    lld pos=0;
    while(t--)
    {
        pos=0;
        memset(visited,0,sizeof(visited));
        sf_d(n);
        fr(i,n)
        {
            cnt=0;
            sf_d(a);
            visited[a]=true;
            for(int j=1; j<a; j++)
                if(!visited[j])
                    cnt++;
            pos+=cnt*fact[n-i-1];
        }
        print_lld(pos+1);
        putchar('\n');
    }

    return 0;
}


