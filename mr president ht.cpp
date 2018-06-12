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

struct node
{
    int i;
    int j;
    int c;
};
struct dset
{
    dset* parent;
};
bool cmp(node x, node y)
{
    return x.c < y.c;
}

dset* makePair()
{
    dset* newNode=new dset;
    newNode->parent=newNode;
    return newNode;
}


dset* findSet(dset *root)
{
    dset* parent=root->parent;
    if(root==parent)
        return parent;
    root->parent=findSet(parent);
    return root->parent;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m,x,y,cnt=0;
    lld k;
    scanf("%d%d%lld",&n,&m,&k);
    node q[m];
    fr(i,m)
    {
        scanf("%d%d%d",&q[i].i,&q[i].j,&q[i].c);
    }

    sort(q,q+m,cmp);

    dset* st[n+1];
    fr(i,n)
        st[i]=makePair();

    lld cost=0;
    stack<lld> s;
    dset *p1,*p2;
    s.push(0);
    fr(i,m)
    {
        x=q[i].i-1; y=q[i].j-1;
        p1=findSet(st[x]);  p2=findSet(st[y]);
        if(p1==p2)
            continue;
        else
        {
            cost+=q[i].c;
            p1->parent=p2;
            s.push(cost);
        }
    }
    bool flag=0;
    fr(i,n-1)
        if(st[i]!=st[i+1])
        {
            flag=1;
            break;
        }
    if(flag)
        printf("-1");
    else
    {
        cnt=0;
        s.pop();
        while(cost > k && !s.empty())
        {
            cnt++;
            cost=s.top()+cnt;
            s.pop();
        }
        if(cost > k)
            printf("-1");
        else
            printf("%d",cnt);
    }
    return 0;
}


