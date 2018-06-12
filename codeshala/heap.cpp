#include<bits/stdc++.h>
using namespace std;

int Size=0;
vector<int> v(100);

void insertHeap( int value){
    v[Size]=value;
    int idx=Size;
    Size++;
    while(idx>0 && v[(idx-1)/2] > value){
        v[idx]=v[(idx-1)/2];
        idx=(idx-1)/2;
    }
    v[idx]=value;
}

void deleteHeap(){
    if(Size > 0){
        v[0]=v[--Size];
        int idx=0;
        int value=v[0];
        int temp=1;
        if(Size>2 && v[1]>v[2])
            temp=2;
        int child=2*idx+temp;
        while(child < Size && v[child] < value){
            v[idx]=v[child];
            idx=child;
            child=2*idx+temp;
        }
        v[idx]=value;
    }
}

int topHeap(){
    if(Size > 0)
        return v[0];
}

int heapSize(){
    return Size;
}
int main()
{
    int n;
    cin>>n;
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a == 1){
                cin>>b;
            insertHeap(b);
        }
        if(a == 2){
            deleteHeap();
        }
        if(a == 3){
            cout<<topHeap()<<"\n";
        }
        if(a==4){
            cout<<heapSize()<<"\n";
        }
    }


}
