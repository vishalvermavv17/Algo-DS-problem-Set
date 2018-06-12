#include<bits/stdc++.h>
using namespace std;

int getMax(int *a, int n){
    assert(n>0);
    int Max=a[0];
    for(int i=1; i<n; i++){
        Max = max(Max,a[i]);
    }
    return Max;
}


void countSort(int *a, int n, int exp){

    vector<vector<int> > v(10);
    int mod=1,tmp;
    while(exp--){
        for(int i=0; i<n; i++){
            tmp=a[i];
            tmp/=mod;
            tmp%=10;
            v[tmp].push_back(a[i]);
        }
        int idx=0;
        for(int i=0; i<10; i++){
            for(int j=0; j<v[i].size(); j++){
                a[idx++]=v[i][j];
            }
            v[i].clear();
        }
        mod*=10;
    }
}

void radixSort(int *a, int n){
    int Max = getMax(a,n);
    int exp=0;
    while(Max){
        exp++;
        Max/=10;
    }
    countSort(a, n, exp);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    radixSort(a,n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
