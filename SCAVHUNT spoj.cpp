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
#define fr(i,a) for(int i=1;i<=a;i++)
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

vector<vector<int> >v;
vector <bool> visited;
stack<string>s;
map<int,string> mis;
map<string,int> msi;

void init(int n){
	v.clear();
	v.resize(n);
	msi.clear();
	mis.clear();
	visited.clear();
	visited.resize(n);
	fill(visited.begin(), visited.end(), false);
	//memset(visited,false,sizeof(visited));
}
void topSort(int i)
{
        visited[i]=true;
        for(int j=0; j<v[i].size(); j++)
        {
            int node=v[i][j];
            if(!visited[node])
                topSort(node);
        }
        s.push(mis[i]);

}
int main()
{
    //std::ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int t,cs=1,cnt,n;
    string s1,s2;
    scanf("%d",&t);

    while(t--)
    {
        cnt=1;
        scanf("%d",&n);
        init(n);
        for(int i=1; i<n; i++)
        {
            cin>>s1>>s2;
            if(msi[s1]==0)
            {
                mis[cnt-1]=s1;
                msi[s1]=cnt;
                cnt++;
            }
            if(msi[s2]==0)
            {
                mis[cnt-1]=s2;
                msi[s2]=cnt;
                cnt++;
            }
            v[msi[s1]-1].push_back(msi[s2]-1);
        }


        for(int i=0; i<n; i++)
            if(!visited[i])
                topSort(i);

        printf("Scenario #%d:\n",cs++);
        while(!s.empty())
        {
            cout<<s.top()<<"\n";
            s.pop();
        }
        printf("\n");
    }

    return 0;
}
