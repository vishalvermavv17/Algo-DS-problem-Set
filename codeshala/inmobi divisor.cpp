#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void findCount(int n, int k, int idx, int len){
    if(len >= k){
        cnt++;
        return ;
    }
    for(int i=idx; i<=n; i++){
        if(i%idx == 0){
            findCount(n,k,i,len+1);
        }
    }
    return;
}

int main(){
    int n,k;
    cin>>n>>k;

    findCount(n,k,1,0);
    cout<<cnt;
    return 0;
}
