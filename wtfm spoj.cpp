#include "bits/stdc++.h"
using namespace std;


//definition
#define gc() getchar()
#define pc() putchar()

#define MOD 1000000007
#define MAX 1009
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
vector<vector<int> >graph(200007);
int a[1000];
bool visited[200007];
int dpf[200007];
int n,k,q,cnt,u,v,idx,distPN,cpy;


void primeArr()
{
    int k=0;
    memset(visited,1,sizeof(visited));
    visited[1]=false;
    a[k++]=2;
    for(int i=3; i <=MAX; i+=2)
    {
        if(visited[i])
         {
             for(int j=i*i; j<=MAX; j+=i+i)
                visited[j]=false;
            a[k++]=i;
         }
    }
}


bool dfs(int u)
{
    if(!visited[u])
    {
        bool flag=false;
        visited[u]=true;
        if(u==v)
            return true;

        for(int j=0; j<graph[u].size(); j++)
        {
            if(dfs(graph[u][j]))
            {
                if(dpf[graph[u][j]-1]>=k)
                    cnt++;
                return true;
            }

        }
    }
    return false;
}

int distinctPrimeFactor(int x)
{
    idx=0;    distPN=0;
    cpy=sqrt(x);
    while(x>1 && a[idx] <= cpy)
    {
        if(x%a[idx]==0)
        {
            distPN++;
            while(x%a[idx]==0)
                x=x/a[idx];
        }
        idx++;
    }
    if(x!=1)
        distPN++;
    return distPN;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    primeArr();
    scanf("%d%d%d",&n,&k,&q);
    //fastscan(n);    fastscan(k);    fastscan(q);
    int gdp[200003];
    fr(i,n)
        //fastscan(gdp[i]);
        scanf("%d",&gdp[i]);

    fr(i,n-1)
    {
        //fastscan(u); fastscan(v);
        sf_d(u);    sf_d(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fr(i,n)
        dpf[i]=distinctPrimeFactor(gdp[i]);

    while(q--)
    {
        memset(visited,0,sizeof(visited));
        cnt=0;
        //fastscan(u);    fastscan(v);
        sf_d(u);    sf_d(v);
        if(dpf[u-1]>=k)
            cnt++;
        dfs(u);
        print_d(cnt);   putchar('\n');
    }

    return 0;
}

