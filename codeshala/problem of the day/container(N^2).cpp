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
    long int ans=0,temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            temp=min(arr[i], arr[j]) * (j-i);
            ans = ans < temp ? temp:ans;
        }
    }
    cout<<ans;
}
