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
#define fr(i,n) for(int i=1;i<n;i++)
#define fe(i,n) for(int i=0;i<=n;i++)

#define sf_d(n) scanf("%d",&n)
#define sf_ld(n) scanf("%ld",&n)
#define sf_lld(n) scanf("%lld",&n)
//fast input
void fastscan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
void fastscan(long int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}


//fast output
void print_d(int n) {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n) {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n) {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

struct node
{
    int data;
    node* next;
    node():next('\0'){};

};
node* a[10005];
bool visited[10005]={false};
int path[10005];
node* insertNode(node* root, int u, int v)
{
    if(!root)
    {
        node * newNode=new node();
        newNode->data=v;
        return newNode;
    }
    node* newNode=new node();
    newNode->next=a[u];
    newNode->data=v;
    return newNode;
}

int dfs(int u)
{

    node *root=a[u];
    if(!root)
        return 0;
    int max1Path=0,max2Path=0;
    int currPath=0;
    while(root)
    {
        if(!visited[root->data])
        {
            visited[root->data]=true;
            currPath=dfs(root->data)+1;
            if(currPath > max2Path && currPath < max1Path)
                max2Path=currPath;
            else if(currPath>=max1Path)
            {
                max2Path=max1Path;
                max1Path=currPath;
            }

            visited[root->data]=false;
        }
        root=root->next;
        currPath=0;
    }
    path[u]=max1Path+max2Path;
    return max1Path;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    fastscan(n);
    memset(a,'\0',sizeof(a));
    fr(i,n)
    {
        int u,v;
        fastscan(u);    fastscan(v);
        a[u]=insertNode(a[u],u,v);
        a[v]=insertNode(a[v],v,u);

    }
    visited[1]=true;
    dfs(1);
    int tmp=0;

    fr(i,n)
        if(tmp < path[i])
            tmp=path[i];
    print_d(tmp);
    return 0;
}


