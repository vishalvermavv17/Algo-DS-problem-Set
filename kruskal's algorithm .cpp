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

struct Set
{
    Set* parent;
    int data;
    Set():data(0),parent(NULL){};
};

struct node
{
    int i;
    int j;
    ld w;
};

bool cmp(node x , node y)
{
    return x.w < y.w;
}


Set* makeSet()
{
    Set* newNode=new Set();
    newNode->parent=newNode;
    return newNode;
}

Set* findSet(Set * root)
{
    Set* parent=root->parent;
    if(parent==root)
        return parent;
    root->parent=findSet(parent);
    return root->parent;
}

void makeUnion(Set *root1, Set* root2)
{
    Set* parent1=findSet(root1);
    Set* parent2=findSet(root2);
    if(parent1!=parent2)
        parent1->parent=parent2;
}

int main()
{
    //std::ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int n,m;
    scanf("%d%d",&n,&m);

    Set* st[n];
    fr(i,n)
        st[i]=makeSet();

    node edg[m];
    fr(k,m)
        cin>>edg[k].i>>edg[k].j>>edg[k].w;

    sort(edg, edg+m, cmp);
    Set* root1,*root2;
    lld resWght=0;
    fr(i,m)
    {
        root1=findSet(st[edg[i].i-1]);    root2=findSet(st[edg[i].j-1]);
        if(root1==root2)
            continue;
        else
        {
            resWght+=edg[i].w;
            makeUnion(st[edg[i].i-1], st[edg[i].j-1]);
        }
    }
    print_lld(resWght);
    return 0;
}

