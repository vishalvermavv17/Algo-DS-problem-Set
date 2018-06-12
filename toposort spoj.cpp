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
#define fr(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)

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
//end of fast output

bool visited[10007]={false};
vector<vector<int> >vec(10000);
struct node
{
    int a;
    int b;
};
bool currVisit[10007]={false};
stack<int> s;
bool cmp(node x, node y)
{
    if(x.a == y.a)
    {
        return x.b < y.b;
    }
    return x.a < y.a;
}

bool topSort(int i)
{
    if(currVisit[i])
        return 1;
        if(!visited[i])
        {
            currVisit[i]=true;
            visited[i]=true;
            for(int j=vec[i].size()-1; j>=0;j--)
                if(topSort(vec[i][j]))
                    return 1;
            //store nodes in topological order
            s.push(i+1);
            currVisit[i]=false;
        }
    return 0;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //total No of nodes
    int n;
    fastscan(n);
    //total no of edges
    int m;
    fastscan(m);
    node a[m];
    int u,v;
    //scan edges from u to v
    for(int i=0; i<m; i++)
        scanf("%d%d",&a[i].a,&a[i].b);

    sort(a,a+m,cmp);
    for(int i=0; i<m; i++)
        vec[a[i].a-1].push_back(a[i].b-1);
    //calls topological sort for each node
    bool flag=1;
    for(int i=n-1; i>=0;i--)
        if(!visited[i])
            if(topSort(i))
            {
                printf("Sandro fails.");
                flag=0;
                break;
            }


    //print the node of graph in topological order
    if(flag)
    {
        while(!s.empty())
        {
            print_d(s.top());   putchar(' ');
            s.pop();
        }
    }


    return 0;
}


