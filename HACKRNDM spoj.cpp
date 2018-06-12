#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

//fast input
void fastscan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}

void fastscan(long int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
//output
void print_d(int n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_ld(ll n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,k;
    fastscan(n);    fastscan(k);
    int a[n];
    for(int i=0; i<n; i++)
        fastscan(a[i]);
    sort(a,a+n);
    int low=1;
    int high=n-1;
    int cnt=0;
    for(int i=0; i<n && low<n; i++)
    {
        high=n-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int tmp=a[mid]-a[i];

            if( tmp == k)
            {
                cnt++;
                break;
            }
            else
                if(tmp < k)
                    low=mid+1;
            else if(tmp > k)
                high=mid-1;
        }
    }
    print_d(cnt);

    return 0;
}


