#include <bits/stdc++.h>
using namespace std;

int main()
{
    //std::ios_base::sync_with_stdio(0);
    //cin.tie(NULL);


    long long int p,q,x,y,a,b;
    char c;
    cin>>p;
    getchar();
    cin>>q;

    cin>>x;
    scanf("%c",&c);
    cin>>y;

    a=(2*x)%p;   b=(2*y)%q;

    cin>>x;
    scanf("%c",&c);
    cin>>y;

    a=(a+x)%p;  b=(b+y)%q;

    cin>>x;
    scanf("%c",&c);
    cin>>y;

    a=(a-x)%p;  b=(b-y)%q;

    while(a!=b)
    {
        if(a<b)
            a+=p;
        else
            b+=q;
    }
    cout<<a;

}
