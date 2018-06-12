#include <bits/stdc++.h>
using namespace std;

int nswap(int a, int b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b<<endl;
    return 0;
}

int nnswap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b<<endl;
    return 0;

}

int main()
{
    int a,b;
    float c,d;
    cin>>a>>b;
    swap(a,b);

    cout<<a<<" "<<b<<endl;
    nswap(a,b);
    nnswap(a,b);
}
