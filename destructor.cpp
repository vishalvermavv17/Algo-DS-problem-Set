#include<bits/stdc++.h>
using namespace std;

class base
{
    int a,x;
public:
    getdata()
    {
        cin>>a;
    }
    base(int x);
    ~base()
    {
        cout<<"free";
    }

};
 base::base(int x)
{
    a=x;
    cout<<a;
    cout<<"\nconstructor created";
};

int main()
{

    int x;
    cin>>x;
    base a(x);
    a.getdata();
    return 0;
}
