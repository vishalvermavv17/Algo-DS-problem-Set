#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int T,N,M,X,Y,temp;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        vector<long int> arr[N+1];
        for(long int i=0;i<M;i++)
        {
            cin>>X>>Y;
            arr[X].push_back(Y);
            arr[Y].push_back(X);
        }
        queue <long int> Q;
        bool mark[10000+1]={0};
        long int level[10000+1]={0};
        mark[1]=true;
        Q.push(1);
        level[1]=1;
        while(!Q.empty())
        {
            temp=Q.front();
            Q.pop();
            for(vector<long int>::iterator it=arr[temp].begin();it!=arr[temp].end();it++)
                if(mark[*it]==false)
                {
                    mark[*it]=true;
                    if((*it)==N)
                    {
                        cout<<level[temp]<<endl;
                        goto label;
                    }
                    Q.push(*it);
                    level[*it]=level[temp]+1;
                }
    }
    label:;
}
return 0;
}

