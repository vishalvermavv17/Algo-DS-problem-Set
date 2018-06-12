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
void scanf(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
void scanf(long int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
void scanf(lld &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}

//end of fast input

//output
void print_d(int n) {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(lld n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n) {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n) {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

struct node
{
    int a;
    int b;
    int w;
};

struct dset
{
    dset* parent;
    int S;
};
int a[100007];
bool visited[100007];
bool cmp(node x, node y)
{
    if(x.w == y.w)
    {
        int arr[4];
        arr[0]=a[x.a-1];    arr[1]=a[x.b-1];
        arr[2]=a[y.a-1];    arr[3]=a[y.b-1];
        sort(arr,arr+4);
        if(a[x.a-1]==arr[3] || a[x.b-1]==arr[3])
            return true;
        else
            return false;
    }
    return x.w>y.w;
}

dset* makeSet(int i)
{
    dset* newNode=new dset;
    newNode->parent=newNode;
    newNode->S=a[i];
    return newNode;
}

dset* findSet(dset* root)
{
    dset* parent=root->parent;
    if(root == parent)
        return parent;
    root->parent=findSet(parent);
    return root->parent;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m,X,u,v;
    lld Sum;
    scanf("%d",&n);    scanf("%d",&m);

    fr(i,n)
        scanf("%d",&a[i]);

    node q[m];
    fr(i,m)
    {
        scanf("%d",&q[i].a);
        scanf("%d",&q[i].b);
        scanf("%d",&q[i].w);
    }

    scanf("%d",&u);    scanf("%d",&v);

    sort(q,q+m,cmp);

    dset* st[n];
    fr(i,m)
        st[i]=makeSet(i);

    dset* p1, *p2;
    fr(i,m)
    {
        if(findSet(st[u-1]) == findSet(st[v-1]))
            break;
        p1=findSet(st[q[i].a-1]);
        p2=findSet(st[q[i].b-1]);
        if(p1 == p2)
            continue;
        else
        {
            X=q[i].w;
            p1->parent=p2;
            p1->S+=p2->S;
            Sum=p1->S;
        }
    }
    printf("%d %d",X,Sum);

    return 0;
}


