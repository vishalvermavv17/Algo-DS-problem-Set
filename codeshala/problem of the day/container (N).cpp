#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin>>n;
    assert(n > 1);
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    long int ans=0,temp=0;
    bool lr[1005]={0},rl[1005]={0};
    for(int i=0; i<n-1; i++){
        if(!lr[arr[i]]){
            for(int j=n-1; j>i; j--){
                if(arr[i] <= arr[j] ){
                    temp=arr[i]*(j-i);
                    break;
                }
            }
            ans = ans < temp ? temp:ans;
            lr[arr[i]]=1;
        }
    }
    for(int i=n-1; i>1; i--){
        if(!rl[arr[i]]){
            for(int j=0; j<i; j++){
                if(arr[i] <= arr[j]){
                    temp=arr[i]*(i-j);
                    break;
                }
            }
            ans = ans < temp ? temp:ans;
            rl[arr[i]]=1;
        }
    }
    cout<<ans;
}
