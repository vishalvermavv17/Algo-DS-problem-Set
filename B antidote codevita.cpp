#include <bits/stdc++.h>
using namespace std;


struct node
{
    int i,j,level;
};
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }

    bool visited[n+1][n+1];
    memset(visited, 0, sizeof(visited));

    queue<node> q;
    node z;
    int x,y;
    cin>>x>>y;
    x--;    y--;

    a[x][y]=5;
    visited[x][y]=1;
    if(x > 0)
    {
        if(a[x-1][y])
        {
            a[x-1][y]=5;
            z.i=x-1;
            z.j=y;
            z.level=5;
            q.push(z);
            visited[x-1][y]=1;
        }

        if(y > 0)
            if(a[x-1][y-1])
            {
                a[x-1][y-1]=5;
                z.i=x-1;
                z.j=y-1;
                z.level=5;
                q.push(z);
                visited[x-1][y-1]=1;
            }
        if(y < n-1)
            if(a[x-1][y+1])
            {
                a[x-1][y+1]=5;
                z.i=x-1;
                z.j=y+1;
                z.level=5;
                q.push(z);
                visited[x-1][y+1]=1;
            }


    }
    if(y > 0)
    {
        if(a[x][y-1])
        {
            a[x][y-1]=5;
            z.i=x;
                z.j=y-1;
                z.level=5;
                q.push(z);
                visited[x][y-1]=1;
        }
    }
    if(y < n-1)
    {
        if(a[x][y+1])
        {
            a[x][y+1]=5;
            z.i=x;
                z.j=y+1;
                z.level=5;
                q.push(z);
            visited[x][y+1]=1;
        }
    }

    if(x < n-1)
    {
        if(a[x+1][y])
        {
            a[x+1][y]=5;
            z.i=x+1;
            z.j=y;
            z.level=5;
            q.push(z);
            visited[x+1][y]=1;

        }
        if( y > 0)
        {
            if(a[x+1][y-1])
            {
                a[x+1][y-1]=5;
                z.i=x+1;
                z.j=y-1;
                z.level=5;
                q.push(z);
                visited[x+1][y-1]=1;
            }
        }
        if(y < n-1)
        {
            if(a[x+1][y+1])
            {
                a[x+1][y+1]=5;
                z.i=x+1;
                z.j=y+1;
                z.level=5;
                q.push(z);
                visited[x+1][y+1]=1;
            }
        }
    }




    node frnt;

    while(!q.empty() )
    {
        frnt=q.front();

        q.pop();
        x=frnt.i;
        y=frnt.j;
        if(frnt.level > 1)
        {

            if(x > 0)
            {
                if(a[x-1][y] && !visited[x-1][y])
                {
                    a[x-1][y]=frnt.level-1;
                    z.i=x-1;
                    z.j=y;
                    z.level=frnt.level-1;
                    q.push(z);
                    visited[x-1][y]=1;
                }

                if(y > 0 &&!visited[x-1][y-1])
                    if(a[x-1][y-1])
                    {
                        a[x-1][y-1]=frnt.level-1;
                        z.i=x-1;
                        z.j=y-1;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x-1][y-1]=1;
                    }
                if(y < n-1 )
                    if(a[x-1][y+1] && !visited[x-1][y+1])
                    {
                        a[x-1][y+1]=frnt.level-1;
                        z.i=x-1;
                        z.j=y+1;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x-1][y+1]=1;
                    }


            }
            if(y > 0 )
            {
                if(a[x][y-1] && !visited[x][y-1])
                {
                    a[x][y-1]=frnt.level-1;
                    z.i=x;
                    z.j=y-1;
                    z.level=frnt.level-1;
                    q.push(z);
                    visited[x][y-1]=1;
                }
            }
            if(y < n-1)
            {
                if(a[x][y+1] && !visited[x][y+1])
                {
                    a[x][y+1]=frnt.level-1;
                    z.i=x;
                        z.j=y+1;
                        z.level=frnt.level-1;
                        q.push(z);
                    visited[x][y+1]=1;
                }
            }

            if(x < n-1)
            {
                if(a[x+1][y] && !visited[x+1][y])
                {
                    a[x+1][y]=frnt.level-1;
                    z.i=x+1;
                    z.j=y;
                    z.level=frnt.level-1;
                    q.push(z);
                    visited[x+1][y]=1;

                }
                if( y > 0)
                {
                    if(a[x+1][y-1] && !visited[x+1][y-1])
                    {
                        a[x+1][y-1]=frnt.level-1;
                        z.i=x+1;
                        z.j=y-1;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x+1][y-1]=1;
                    }
                }
                if(y < n-1)
                {
                    if(a[x+1][y+1] && !visited[x+1][y+1])
                    {
                        a[x+1][y+1]=frnt.level-1;
                        z.i=x+1;
                        z.j=y+1;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x+1][y+1]=1;
                    }
                }
            }
        }
    }

    //*********************ANTIDOTE*************
    cin>>x>>y;
    x--;    y--;
    memset(visited, 0, sizeof(visited));
    if(a[x][y] > 1)
    {

        a[x][y]=1;
        visited[x][y]=1;

        if(x > 0)
        {
            if(a[x-1][y])
            {
                a[x-1][y]=1;
                z.i=x-1;
                z.j=y;
                z.level=1;
                q.push(z);
                visited[x-1][y]=1;
            }

            if(y > 0)
                if(a[x-1][y-1])
                {
                    a[x-1][y-1]=1;
                    z.i=x-1;
                    z.j=y-1;
                    z.level=5;
                    q.push(z);
                    visited[x-1][y-1]=1;
                }
            if(y < n-1)
                if(a[x-1][y+1])
                {
                    a[x-1][y+1]=1;
                    z.i=x-1;
                    z.j=y+1;
                    z.level=5;
                    q.push(z);
                    visited[x-1][y+1]=1;
                }


        }
        if(y > 0)
        {
            if(a[x][y-1])
            {
                a[x][y-1]=1;
                z.i=x;
                    z.j=y-1;
                    z.level=5;
                    q.push(z);
                    visited[x][y-1]=1;
            }
        }
        if(y < n-1)
        {
            if(a[x][y+1])
            {
                a[x][y+1]=1;
                z.i=x;
                    z.j=y+1;
                    z.level=5;
                    q.push(z);
                visited[x][y+1]=1;
            }
        }

        if(x < n-1)
        {
            if(a[x+1][y])
            {
                a[x+1][y]=1;
                z.i=x+1;
                z.j=y;
                z.level=5;
                q.push(z);
                visited[x+1][y]=1;

            }
            if( y > 0)
            {
                if(a[x+1][y-1])
                {
                    a[x+1][y-1]=1;
                    z.i=x+1;
                    z.j=y-1;
                    z.level=5;
                    q.push(z);
                    visited[x+1][y-1]=1;
                }
            }
            if(y < n-1)
            {
                if(a[x+1][y+1])
                {
                    a[x+1][y+1]=1;
                    z.i=x+1;
                    z.j=y+1;
                    z.level=5;
                    q.push(z);
                    visited[x+1][y+1]=1;
                }
            }
        }
        //***********While goes here************


        while(!q.empty() )
        {
            frnt=q.front();

            q.pop();
            x=frnt.i;
            y=frnt.j;

            {

                if(x > 0)
                {
                    if(a[x-1][y] > 1 && !visited[x-1][y])
                    {
                        a[x-1][y]--;
                        z.i=x-1;
                        z.j=y;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x-1][y]=1;
                    }

                    if(y > 0 &&!visited[x-1][y-1])
                        if(a[x-1][y-1] > 1)
                        {
                            a[x-1][y-1]--;
                            z.i=x-1;
                            z.j=y-1;
                            z.level=frnt.level-1;
                            q.push(z);
                            visited[x-1][y-1]=1;
                        }
                    if(y < n-1 )
                        if(a[x-1][y+1] > 1  && !visited[x-1][y+1])
                        {
                            a[x-1][y+1]--;
                            z.i=x-1;
                            z.j=y+1;
                            z.level=frnt.level-1;
                            q.push(z);
                            visited[x-1][y+1]=1;
                        }


                }
                if(y > 0 )
                {
                    if(a[x][y-1] > 1 && !visited[x][y-1])
                    {
                        a[x][y-1]--;
                        z.i=x;
                        z.j=y-1;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x][y-1]=1;
                    }
                }
                if(y < n-1)
                {
                    if(a[x][y+1] > 1 && !visited[x][y+1])
                    {
                        a[x][y+1]--;
                        z.i=x;
                            z.j=y+1;
                            z.level=frnt.level-1;
                            q.push(z);
                        visited[x][y+1]=1;
                    }
                }

                if(x < n-1)
                {
                    if(a[x+1][y] > 1 && !visited[x+1][y])
                    {
                        a[x+1][y]--;
                        z.i=x+1;
                        z.j=y;
                        z.level=frnt.level-1;
                        q.push(z);
                        visited[x+1][y]=1;

                    }
                    if( y > 0)
                    {
                        if(a[x+1][y-1] > 1 && !visited[x+1][y-1])
                        {
                            a[x+1][y-1]--;
                            z.i=x+1;
                            z.j=y-1;
                            z.level=frnt.level-1;
                            q.push(z);
                            visited[x+1][y-1]=1;
                        }
                    }
                    if(y < n-1)
                    {
                        if(a[x+1][y+1] >1 && !visited[x+1][y+1])
                        {
                            a[x+1][y+1]--;
                            z.i=x+1;
                            z.j=y+1;
                            z.level=frnt.level-1;
                            q.push(z);
                            visited[x+1][y+1]=1;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}


