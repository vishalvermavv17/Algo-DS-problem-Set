#include "bits/stdc++.h"
using namespace std;


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

bool adj[15007][15007];
int visit[15007]={0};
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,a,b,w,x,y;
    llu wght;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        wght=0;
        scanf("%d",&n);

        fr(i,n)
            fr(j,n+1)
                adj[i][j]=false;
        fr(i,n+1)
            visit[i]=20000;

        fr(k,n-1)
        {
            scanf("%d%d%d",&a,&b,&w);
            x=min(a,b); y=max(a,b);
            adj[x][y]=1;
            wght+=w;
            if(visit[x] > w)
                visit[x]=w;
            if(visit[y] > w)
                visit[y]=w;
        }
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(!adj[i][j])
                    wght=wght+max(visit[i],visit[j])+1;
            }
        }
        printf("%llu\n",wght);
    }

    return 0;
}


