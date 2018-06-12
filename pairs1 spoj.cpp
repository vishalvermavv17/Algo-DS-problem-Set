#include<bits/stdc++.h>
using namespace std;

int findpairs(int , int , int []);

int main()
{
    int N,K;
    cin>>N>>K;
    int a[N];
    for(int i=0; i<N; i++)
        cin>>a[i];

    sort(a,a+N);
    int result = findpairs(N,K,a);

    cout<<result;
    return 0;
}
int findpairs(int N, int K, int a[])
{
    int no_of_pairs=0;

    for(int i=0; a[i]+K <= a[N-1]; i++)
    {
        bool flag = binary_search(a+i+1 , a+N, a[i]+K);

        if(flag)
            no_of_pairs++;
    }

    return no_of_pairs;
}
