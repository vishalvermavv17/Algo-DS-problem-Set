#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    multiset<int> set;
    multiset<int>::iterator f,r;

    llu cost=0;
    register int n;
    scanf("%d",&n);

    while(n--)
    {
        register int k;
        scanf("%d",&k);
        while(k--)
        {
            int i;
            scanf("%d",&i);
            set.insert(i);
        }
        f=set.begin();
        r=set.end();
        r--;
        cost+=*r-*f;
        set.erase(f);
        set.erase(r);
    }
    printf("%llu",cost);
    return 0;
}


