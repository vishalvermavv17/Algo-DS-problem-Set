#include <iostream>
using namespace std;

template <class t> class A{
t a;
public:
    void setd(t x)
    {
        a=x;
    }
    void show()
    {
        cout<<a;
    }

};

int main()
{
    A <int>a;
    A <float>b;

    a.setd(5);
    a.show();
    b.setd(51.878);
    b.show();
}
