#include"iostream"
using namespace std;

int main()
{
    int a=11;
    cout<<-a;
    a=a-(-a & a);
    cout<<a;
}
