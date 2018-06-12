#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
            queue <int> q;
            q.push(1);
            int node;
            while(!q.empty())
            {
                node=q.front();
                if(node%n==0)
                    break;
                node=node*10;
                q.push(node);
                node=node+1;
                q.push(node);
                q.pop();
            }
            cout<<node<<endl;

    }
}
