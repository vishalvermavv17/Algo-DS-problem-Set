#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int n;
    cin>>n;

    vector<long long> v;
    long long l,r,temp;
    map<long long, long long> m;
    for(long int i=0; i<n; i++){
        cin>>l>>r;
        // if(l > r)
        // {
        //     temp=r; r=l; l=temp;
        // }

        v.push_back(l);
        v.push_back(r);
        m[l]= m[l]>r ? m[l]:r;
    }

    sort(v.begin(),v.end());

    assert(n>0);
    long long len=2*n;
    long long Max=v[0];
    cout<<Max<<" ";
    for(long int i=0; i<len; i++){
        if(Max >= v[i]){
            Max = max(Max, m[v[i]]);
        }
        else{
            cout<<Max<<"\n"<<v[i]<<" ";
            Max = v[i];
        }
        //cout<<v[i]<<" "<<Max<<" "<<m[v[i]]<<endl;
    }
    cout<<Max;
}

