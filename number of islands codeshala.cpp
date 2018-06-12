#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
#define row 500
#define col 500
bool visited[row][col];

void dfs(bool a[row][col], int i, int j, int n, int m)
{
    static int rowNbr[]={-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[]={-1, 0, 1, -1, 1, -1, 0, 1};
    visited[i][j]=true;
    for(int k=0; k<8; k++)
    {

        if( i+rowNbr[k] >= 0 && i+rowNbr[k] < n && j+colNbr[k] >= 0 && j+colNbr[k] < m && a[i+rowNbr[k]][j+colNbr[k]] && !visited[i+rowNbr[k]][j+colNbr[k]] )

         dfs(a, i+rowNbr[k], j+colNbr[k], n, m);
    }

}

int countIslands(bool a[row][col], int n, int m)
{
    memset(visited, 0, sizeof(visited));
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] && !visited[i][j])
            {
                cnt++;
                dfs(a, i, j, n, m);
            }
        }
    }
    return cnt;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    bool a[row][col];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char c;
            cin>>c;
            if(c=='0')
                a[i][j]=false;
            else
                a[i][j]=true;
        }
    }
    cout<<countIslands(a, n, m);

    return 0;
}


#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

struct node
{
    int idx;
    node* next;
}*v[250007];
bool visited[250007]={false};

node* insertNode(node *a, int i)
{
    if(!a)
    {
        node* newNode=new node;
        newNode->idx=i;
        newNode->next='\0';
        return newNode;
    }
    a->next=insertNode(a->next, i);
    return a;
}
void dfs(int x)
{
    if(!visited[x])
    {
        visited[x]=true;
        node *currNode=v[x];
        while(currNode)
        {
            dfs(currNode->idx);
            currNode=currNode->next;
        }
        return ;
    }
    return ;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    char a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x=i*m+j;
            if(a[i][j]=='1')
            {
                if(i-1 >= 0)
                {
                    if(j-1 >=0 && a[i-1][j-1]=='1')
                        v[x]=insertNode(v[x], (i-1)*m+(j-1));
                    if(a[i-1][j]=='1')
                        v[x]=insertNode(v[x], (i-1)*m+j);
                    if(j+1 < m && a[i-1][j+1]=='1')
                        v[x]=insertNode(v[x], (i-1)*m+j+1);
                }
                if(j-1 >= 0 && a[i][j]=='1')
                    v[x]=insertNode(v[x],(i)*m+j);
                if(j+1 < m && a[i][j+1]=='1')
                    v[x]=insertNode(v[x], i*m+j+1);

                if(i+1 < n)
                {
                    if(j-1 >=0 && a[i+1][j-1]=='1')
                        v[x]=insertNode(v[x], (i+1)*m+j-1);
                    if(a[i+1][j]=='1')
                        v[x]=insertNode(v[x], (i+1)*m+j);
                    if(j+1 < m && a[i+1][j+1]=='1')
                        v[x]=insertNode(v[x], (i+1)*m+j+1);
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<m*n; i++)
    {
        if(a[i/m][i%m]=='1' && !visited[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans;

    return 0;
}

