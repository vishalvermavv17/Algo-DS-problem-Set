#include<bits/stdc++.h>
using namespace std;

struct trie{
    trie* a[2];
    trie(){
        a[0]=a[1]='\0';
    }
};


int main(){
    long int n;
    cin>>n;

    long int arr[n];
    for(long int i=0; i<n; i++ )
        cin>>arr[i];
    trie* root= new trie;
    long int currentBit;
    trie* ptr;
    for(long int i=0; i<n; i++){
        ptr=root;
        for(int j=21; j>=0; j--){
            currentBit=arr[i]&(1<<j);
            currentBit = currentBit > 0 ? 1:0;

            if(!ptr->a[currentBit]){
                ptr->a[currentBit] = new trie;
            }
            ptr = ptr->a[currentBit];
        }
    }
    long int localMax=0,Max=0;
    for(long int i=0; i<n; i++){
        ptr=root; localMax=0;
        for(int j=21; j>= 0; j--){
            currentBit=arr[i]&(1<<j);
            currentBit = currentBit > 0 ? 0:1;
            if(ptr->a[currentBit]){
                localMax=localMax<<1|1;
                ptr=ptr->a[currentBit];
            }
            else{
                localMax = localMax<<1;
                ptr=ptr->a[currentBit^1];
            }

        }
        Max = Max > localMax ? Max:localMax;
    }
    cout<<Max;
    return 0;
}
