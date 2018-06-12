#include <cmath>
#include <cstdio>
#include <vector>
#include<stack>
#include <iostream>
#include<fstream>
#include <algorithm>
using namespace std;
vector<long int> v(1000000);
int Size=0;
void insertHeap(long int value){
    v[++Size]=value;
    int temp=Size;
    while(Size/2 > 0 && value < v[Size/2]){
        v[Size]=v[Size/2];
        Size/=2;
    }
    v[Size]=value;
    Size=temp;
}
long int  minHeap(){
    long int value=v[1];

    return value;
}
void deleteHeap(long int value){
    int i;
    for(i=1; i<=Size && v[i] != value; i++);

    v[i]=v[Size--];
    value=v[i];
    int flag=0;
    if(Size>=2*i+1)
        flag = v[2*i] > v[2*i+1] ? 1:0;
    if(2*i+flag <= Size && value > v[2*i+flag] ){
        v[i]=v[2*i+flag];
        i=2*i+flag;
    }
    while(2*i <= Size && value > v[2*i]){
        v[i]=v[2*i];
        i=i*2;

    }
    v[i]=value;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin>>q;
    int i;

    fstream myfile;
    myfile.open("new.txt",fstream::out);
    stack<int> s;
    long int value;
    while(q--){
        cin>>i;
        if(i==1){
            cin>>value;
            insertHeap(value);
            s.push(value);
        }
        else if(i==2){
            if(!s.empty()){
                value=s.top();
                s.pop();
                deleteHeap(value);
            }
        }
        else{
            if(!s.empty())
                myfile<<minHeap()<<"\n";
            else
                myfile<<"-1\n";
        }
        //cout<<s.top()<<Size<<v[0]<<v[1]<<v[2]<<v[3]<<"| ";
    }

    return 0;
}
