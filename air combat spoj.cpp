#include<bits/stdc++.h>
using namespace std;

// ******must check error before submitting again**********

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int x,y,z,x2,y2,z2;
        cin>>x>>y>>z>>x2>>y2>>z2;

        bool hx[1250]={false},hy[1250]={false},hz[1250]={0};
        int q;
        cin>>q;


        while(q--)
        {
            char qry;
            cin>>qry;
            switch(qry)
            {
                case 'U' :  int ri;
                            cin>>x2>>y2>>z2>>ri;
                            for(int i=-ri; i<=ri; i++)
                            {
                                hx[x2-i]=!hx[x2-i];
                                hy[y2-i]=!hy[y2-i];
                                hz[z2-i]=!hz[z2-i];
                            }
                            break;
                case 'Q' :  cin>>x2>>y2>>z2;
                            if(hx[x2]==1 && hy[y2]==1 && hz[z2]==1)
                                cout<<"Friend\n";
                            else
                                cout<<"Enemy\n";
            }
        }
    }
    return 0;
}
