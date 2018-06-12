#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

//fast input
void fastscan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}

void fastscan(long int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
//output
void print_ld(ll n) {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_d(int n) {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}


int main()
{
    std::ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int n;
    cin>>n;//fastscan(n);
    while(n!=0)
    {
        cout<<n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];//fastscan(a[i]);
        sort(a,a+n);
        int Max=n-1;
        int cnt=0,idx;
        for(int i=0; i<n-2; i++)
        {
            bool flag=1;
            for(int j=i+1; j<=Max && flag; j++)
            {
                flag=0;
                int low=j+1;    int high=n-1;   int k=a[i]+a[j];
                while(low<=high)
                {
                    int mid=(low+high)>>1;
                    if(mid-1 >= 0 && a[mid-1]<=k && a[mid] > k )
                    {

                            idx=mid;
                            flag=1;
                            break;

                    }
                    else if(a[mid] > k)
                        high=mid;
                    else
                        low=mid+1;

                }
                if(low <= high)
                    cnt+=(n-idx);
            }
            printf("%d",cnt);
            //print_d(cnt);
            //putchar('\n');
            //fastscan(n);
            cin>>n;
        }
    }

    return 0;
}


