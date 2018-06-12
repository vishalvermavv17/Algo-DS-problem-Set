#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    int arr[n][m];
    bool visited[n][m];

    for(int j=0; j<n; j++){
        cin>>s[j];
    }

    pair<int,int> p;
    queue<pair<int,int> > qidx;
    queue<int> qlevel;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]=false;
            if(s[i][j] == 'G')
            {
                p.first=i;
                p.second=j;
                qidx.push(p);
                qlevel.push(0);
                visited[i][j]=true;
            }
            else if(s[i][j] == 'B'){
                visited[i][j]=true;
            }
            else
                arr[i][j]=-1;
        }
    }
    int level,i,j;
    while(!qidx.empty()){
        p=qidx.front();
        i=p.first;
        j=p.second;
        level=qlevel.front();

        //update current room with min dist
        if(s[i][j] == '0')
            arr[i][j] = level;

        //push other available room
        if(i > 0 ){
            if(s[i-1][j]=='0' && !visited[i-1][j]){
                visited[i-1][j]=true;
                p.first=i-1;
                p.second=j;
                qidx.push(p);
                qlevel.push(level+1);
            }
        }
        if(i < n-1){
            if(s[i+1][j]=='0' && !visited[i+1][j]){
                visited[i+1][j]=true;
                p.first=i+1;
                p.second=j;
                qidx.push(p);
                qlevel.push(level+1);
            }
        }
        if(j > 0 ){
            if(s[i][j-1]=='0' && !visited[i][j-1]){
                visited[i][j-1]=true;
                p.first=i;
                p.second=j-1;
                qidx.push(p);
                qlevel.push(level+1);
            }
        }
        if(j < m-1){
            if(s[i][j+1]=='0' && !visited[i][j+1]){
                visited[i][j+1]=true;
                p.first=i;
                p.second=j+1;
                qidx.push(p);
                qlevel.push(level+1);
            }
        }

        qidx.pop();
        qlevel.pop();
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(s[i][j] == '0')
                cout<<arr[i][j]<<" ";
            else
                cout<<s[i][j]<<" ";
        }
        cout<<"\n";
    }

}
