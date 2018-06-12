#include <bits/stdc++.h>
using namespace std;

int cnt=0;
void possibleWays(vector<vector<int> >&v, int currNode, int des, int len, int l, int r){
    if(len > r)
        return;
    if(len >= l && len <= r && currNode == des)
        cnt++;
    for(int i=0; i<v[currNode].size(); i++){
        if(v[currNode][i])
            possibleWays(v, i, des, len+1, l, r);
    }
    return ;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int> > v(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j]=0;
        }
    }
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        v[a-1][b-1] = 1;
    }
    int l,r;
    cin>>l>>r;
    int src,des;
    cin>>src>>des;

    possibleWays(v, src-1, des-1, 0, l, r);
    cout<<cnt;

    return 0;
}
