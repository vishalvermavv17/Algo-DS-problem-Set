#include <bits/stdc++.h>
using namespace std;

string inputString,sortedString;
long int j;
map<long int,long> w;
int visited[26];

int computeWeight(long int i, long int len){
    if(i == len-1)
    {
        w[i]=1;
        return w[i];
    }
    w[i]=( (len-i)*computeWeight(i+1, len) )% 1000003;
    return w[i];
}

long int rankOfCurrentIdx(long int i, long int len){
    if(len-1 == i)
        return 1;
    if(sortedString[j] == inputString[i]){
        visited[j]=1;
        while(visited[j]=0 || visited[j]==-1)
            j++;
        return 0;
    }

    long int diff=0;

    for(int k=j; k<inputString[i]-'a'; k++)
        if(visited[k]==0)
            diff++;

    return (diff*w[i+1]) % 1000003;
}


int main()
{
    cin>>inputString;
    sortedString=inputString;
    sort(sortedString.begin(),sortedString.end());

    long int len=inputString.length();
    for(int i=0; i<26; i++)
        visited[i]=-1;
    for(int i=0; i<len; i++)
        visited[inputString[i]-'a']=0;
    computeWeight(0,len);
    long int ans;
    ans=j=0;

    for(long int i=0; i<len; i++){
        ans=( ans+rankOfCurrentIdx(i,  len) ) % 1000003;
        visited[inputString[i]-'a']=1;
    }

    cout<<ans;
}
