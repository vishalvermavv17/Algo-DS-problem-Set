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

int inEdge[10000]={0};
struct node
{
    int a;
    int b;
};
bool cmp(node &x, node &y)
{
    if(x.a == y.a)
        return x.b > y.b;
    return x.a < y.a;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    fastscan(n);
    int m;
    fastscan(m);
    node edges[m];
    fr(i,m)
    {
        int u,v;
        fastscan(u);    fastscan(v);
        edges[i].a=u-1; edges[i].b=v-1;
        inEdge[v-1]++;
    }
    sort(edges, edges+m, cmp);

    stack<int> q;
    for(int i=n-1; i>=0; i--)
        if(!inEdge[i])
            q.push(i);
    vector<vector<int> >vec(10000);
    queue<int>que;
    for(int i=0; i<m; i++)
        vec[edges[i].a].push_back(edges[i].b);
    int cnt=0;
    while(!q.empty())
    {
        int currNode=q.top();
        q.pop();
        que.push(currNode+1);
        cnt++;
        for(int i=0; i<vec[currNode].size(); i++)
        {
            inEdge[vec[currNode][i]]--;
            if(!inEdge[vec[currNode][i]])
                q.push(vec[currNode][i]);
        }
    }
    if(cnt==n)
        while(!que.empty())
        {print_d(que.front());   putchar(' ');  que.pop();}
    else
        printf("Sandro fails.");
    return 0;
}


