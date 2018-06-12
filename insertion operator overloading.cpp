#include <iostream>
using namespace std;

class complex
{
    int a,b;
public:
    void setdata(int x , int y)
    {
        a=x;
        b=y;
    }
    void showdata()
    {
        cout<<a<<b;
    }
    friend istream& operator <<(istream &, complex &);

};

istream& operator <<(istream & din, complex& c)
{
    cin>>c.a>>c.b;
    return din;
}

int main()
{
    complex c1,c2;
    c1.setdata(3,5);
    cin<<c2;
    c2.showdata();
    return 0;

};
