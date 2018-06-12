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

string keys[8],str;


void letterCombination(string arr, string localString, int idx){
    if(!arr[idx]){
        str.append(localString);
        return;
    }
    int len=keys[arr[idx]-'2'].length();
    string temp=localString;
    for(int i=0; i<len; i++){
        char c = keys[arr[idx]-'2'][i];

        localString.push_back(c);
        letterCombination(arr, localString, idx+1);
        localString=temp;
    }
    return;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string arr;
    cin>>arr;
    keys[0]="abc";  keys[1]="def"; keys[2]="ghi"; keys[3]="jkl"; keys[4]="mno"; keys[5]="pqrs"; keys[6]="tuv"; keys[7]="wxyz";
    letterCombination(arr, " ", 0);
    for(int i=1; str[i]; i++){
        cout<<str[i];
    }

    return 0;
}


