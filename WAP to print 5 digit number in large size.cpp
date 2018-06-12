#include<iostream>
using namespace std;

void print1(int x)
{
    switch(x)
    {
        case 3:
    cout<<"#####  ";
    break;
    case 2:
    cout<<"#####  ";
    break;
    case 1:
    cout<<" #   ";
    break;
    case 4:
    cout<<"#      ";
    break;
    case 5:
    cout<<"#####  ";
    }
}
void print2(int x)
{
    switch(x)
    {
        case 3:
    cout<<"    #  ";
    break;
    case 2:
    cout<<"    #  ";
    break;
    case 1:
    cout<<"##   ";
    break;
    case 4:
    cout<<"#      ";
    break;
    case 5:
    cout<<"#      ";
    }
}
void print3(int x)
{
    switch(x)
    {
        case 3:
    cout<<"    #  ";
    break;
    case 2:
    cout<<"    #  ";
    break;
    case 1:
    cout<<" #   ";
    break;
    case 4:
    cout<<"#      ";
    break;
    case 5:
    cout<<"#      ";
    }
}
void print4(int x)
{
    switch(x)
    {
        case 3:
    cout<<"#####  ";
    break;
    case 2:
    cout<<"    #  ";
    break;
    case 1:
    cout<<" #   ";
    break;
    case 4:
    cout<<"# #    ";
    break;
    case 5:
    cout<<"#####  ";
    }

}
void print5(int x)
{
    switch(x)
    {
        case 3:
    cout<<"    #  ";
    break;
    case 2:
    cout<<"#####  ";
    break;
    case 1:
    cout<<" #   ";
    break;
    case 4:
    cout<<"#####  ";
    break;
    case 5:
    cout<<"    #  ";
    }
}
void print6(int x)
{
    switch(x)
    {
        case 3:
    cout<<"    #  ";
    break;
    case 2:
    cout<<"#      ";
    break;
    case 1:
    cout<<" #   ";
    break;
    case 4:
    cout<<"  #    ";
    break;
    case 5:
    cout<<"    #  ";
    }
}
void print7(int x)
{
    switch(x)
    {
        case 3:
    cout<<"    #  ";
    break;
    case 2:
    cout<<"#      ";
    break;
    case 1:
    cout<<" #   ";
    break;
    case 4:
    cout<<"  #    ";
    break;
    case 5:
    cout<<"    #";
    }
}
void print8(int x)
{
    switch(x)
    {
        case 3:
    cout<<"#####  ";
    break;
    case 2:
    cout<<"#####  ";
    break;
    case 1:
    cout<<"###  ";
    break;
    case 4:
    cout<<"  #    ";
    break;
    case 5:
    cout<<"#####  ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a,b,c,d,e;
    a=n%10; n/=10;
    b=n%10; n/=10;
    c=n%10; n/=10;
    d=n%10; n/=10;
    e=n%10;

    print1(e);print1(d);print1(c);print1(b);print1(a);cout<<"\n";
    print2(e);print2(d);print2(c);print2(b);print2(a);cout<<"\n";
    print3(e);print3(d);print3(c);print3(b);print3(a);cout<<"\n";
    print4(e);print4(d);print4(c);print4(b);print4(a);cout<<"\n";
    print5(e);print5(d);print5(c);print5(b);print5(a);cout<<"\n";
    print6(e);print6(d);print6(c);print6(b);print6(a);cout<<"\n";
    print7(e);print7(d);print7(c);print7(b);print7(a);cout<<"\n";
    print8(e);print8(d);print8(c);print8(b);print8(a);cout<<"\n";

}
