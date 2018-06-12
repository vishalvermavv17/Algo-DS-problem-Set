#include<bits/stdc++.h>

using namespace std;

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};
int main()
{
    pair<int, int> p[2];
    p[0].first=0;   p[0].second=5;
    p[1].first=1;    p[1].second=4;
    priority_queue<pair<int,int>,vector<pair<int, int> >,CompareDist> pq;
    pq.push(p[0]);
    pq.push(p[1]);
    cout<<pq.top().first<<" "<<pq.top().second;
}
