#include <iostream>
using namespace std;

struct node{
    int c;
    bool i;
}q[100];


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;

    int len=0,currlen=0,flag=1,cnt=0,zero=0,one=0;;
    int a[200];
    for(int i=0; i< n; i++)
    {
        cin>>a[i];

        if(a[i])
        {
            if(!flag)
            {
                q[j].i=0;
                q[j].c=zero;
                j++;
                zero=0;

            }
            cnt++;
            one++;
            currlen++;
        }
        else
        {
            if(currlen > len)
                len=currlen;
            currlen=0;
            if()
        }
    }


    if( currlen > len )
        len=currlen;

    if(n==1)
        cout<<cnt;
    else if( cnt>len )
        cout<<++len;
    else
        cout<<len;

    return 0;
}

