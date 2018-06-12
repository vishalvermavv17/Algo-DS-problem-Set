#include <bits/stdc++.h>
using namespace std;

class base{
public:
    virtual add()=0;
};

class sum2: public virtual base{
protected:
    int a=1,b=2;
public:

    add()
{
    cout<<a+b<<endl;
}

};

class sum3: public virtual base{
protected:
    int a=3,b=4,c=5;
public:
    add()
{
    cout<<a+b+c<<endl;
}
};

int main()
{
    sum2 a1;
    sum3 b1;
    a1.add();
    b1.add();
    return 0;
}
