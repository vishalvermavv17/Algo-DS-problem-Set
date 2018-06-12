#include<bits/stdc++.h>
using namespace std;

string keys[8];
string s[2];
void letterCombination(string arr, int idx, int arrLen){
    if(idx+1 == arrLen){
        s[idx%2]=keys[arr[idx]-'2'];
        //cout<<s[idx%2]<<"\n";
        return;
    }
    int len=keys[arr[idx]-'2'].length();

    for(int i=0; i<len; i++){
        if(s[(idx+1) % 2].empty()){
            letterCombination(arr, idx+1, arrLen);
            s[idx % 2]="";
        }
        int diff=arrLen-(idx+1);
        for(int j=0; j<s[(idx+1) % 2].length(); j++){
            if(j % diff == 0)
                s[idx % 2]+=keys[arr[idx]-'2'][i];
            s[idx % 2]+=s[(idx+1) % 2][j];
        }

    }
    //cout<<s[idx%2]<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string arr;

    cin>>arr;
    keys[0]="abc";  keys[1]="def"; keys[2]="ghi"; keys[3]="jkl"; keys[4]="mno"; keys[5]="pqrs"; keys[6]="tuv"; keys[7]="wxyz";
    int arrLen=arr.length();
    letterCombination(arr, 0, arrLen);


    cout<<s[0][0];
    for(int i=1; s[0][i]!='\0'; i++){
        if(i % arrLen == 0)
            cout<<" ";
        cout<<s[0][i];
    }
}
