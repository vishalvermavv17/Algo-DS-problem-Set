#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
int idx=0;
int n,m;
char a[41][41];
struct node
{
    char data;
    int idx;
    node* next;
};
int top=0,tmp;
char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
node* v[1700];
bool visited[1700]={false};

node* insertNode(node* a, char y, int i)
{
    if(!a)
    {
        node* newNode=new node;
        newNode->data=y;
        newNode->idx=i;
        newNode->next='\0';
        return newNode;
    }
    a->next=insertNode(a->next, y, i);
    return a;
}

bool dfs(int x)
{
    if(!visited[x])
    {
        if( a[x/m][x%m] != s[top]){
            return false;
            }

        node* currNode=v[x];
        visited[x]=true;
        top++;
        if(top > tmp)
            tmp=top;
        if(top == 26)
            return true;
        while(currNode)
        {
            bool flag=dfs(currNode->idx);
            if(flag)
                return true;
            currNode=currNode->next;
        }
        top--;
    }
    visited[x]=false;
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=0; i< m*n; i++)
        v[i]='\0';


    for( int i=0; i<n; i++)
    {
        for( int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }

    for( int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j-1 >= 0)
                v[idx]=insertNode(v[idx], a[i][j-1], i*m+j-1);

            if(j+1 < m)
                v[idx]=insertNode(v[idx], a[i][j+1], i*m+j+1);

            if( i-1 >= 0)
            {
                v[idx]=insertNode(v[idx], a[i-1][j], (i-1)*m+j);
                if(j-1 >= 0)
                    v[idx]=insertNode(v[idx], a[i-1][j-1], (i-1)*m+j-1);


                if(j+1 < m)
                    v[idx]=insertNode(v[idx], a[i-1][j+1], (i-1)*m+j+1);
            }
            if( i+1 < n)
            {
                v[idx]=insertNode(v[idx], a[i+1][j], (i+1)*m+j);
                if( j-1 >= 0)
                    v[idx]=insertNode(v[idx], a[i+1][j-1], (i+1)*m+j-1);
                if( j+1 < m)
                    v[idx]=insertNode(v[idx], a[i+1][j+1], (i+1)*m+j+1);
            }
            idx++;
        }
    }
    int ans=0;
    for( int i=0;i<idx ; i++)
    {
        top=0;  tmp=0;
        dfs(i);
        if(tmp > ans)
            ans=tmp;
    }
    cout<<ans;

    return 0;
}





