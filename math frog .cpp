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
    int i,j;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n; cin>>n;
    bool a[n][n];
    string s;

    for(int i=0; i<n; i++)
    {
        s.clear();
        cin>>s;
        for( int j=0; j<2*n; j+=2)
        {
            if(s[j]=='1')
                a[i][j/2]=1;
            else
                a[i][j/2]=0;
        }
    }


    node frog,mate;
    cin>>s;
    frog.i=s[0]-48;    frog.j=s[2]-48;
    cin>>s;
    mate.i=s[0]-48;    mate.j=s[2]-48;


    int cnt=0,level=0,jump=0;
    bool visited[n+1][n+1], flag=0;
    memset(visited, 0, sizeof(visited));


    queue<int> qi,qj,ql;
    qi.push(frog.i-1);    qj.push(frog.j-1);    ql.push(0);
    while(!qi.empty() && !qj.empty() && !flag)
    {
        node currNode;
        currNode.i=qi.front();  currNode.j=qj.front();  level=ql.front();
        qi.pop();   qj.pop();   ql.pop();


        if(!visited[currNode.i][currNode.j])
        {

            visited[currNode.i][currNode.j]=1;
            if(level != cnt)
            {
                jump++;
                cnt=level;
            }
            if(currNode.i==mate.i-1 && currNode.j==mate.j-1)
                flag=1;
            for(int k=currNode.j-1; k>=0; k--)
            {
                if(a[currNode.i][k])
                {
                    qi.push(currNode.i);    qj.push(k); ql.push(level+1);
                    break;
                }
            }
            for(int k=currNode.j+1; k<n; k++)
            {
                if(a[currNode.i][k])
                {
                    qi.push(currNode.i);    qj.push(k); ql.push(level+1);
                    break;
                }
            }
            for(int k=currNode.i-1; k>=0; k--)
            {
                if(a[k][currNode.j])
                {
                    qi.push(k);    qj.push(currNode.j); ql.push(level+1);
                    break;
                }
            }
            for(int k=currNode.j+1; k<n; k++)
            {
                if(a[k][currNode.j])
                {
                    qi.push(k);    qj.push(currNode.j); ql.push(level+1);
                    break;
                }
            }
        }
    }
    cout<<jump;

    return 0;
}


