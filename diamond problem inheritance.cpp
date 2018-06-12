#include <bits/stdc++.h>
using namespace std;

class  game{
public:
    display()
    {
        cout<<"This is game class"<<endl;
    }
};

class player : public virtual game{
public:
    putsdata()
    {
        cout<<"This is player class"<<endl;
    }

};
class score: public virtual game{
public:
    putdata()
    {
        cout<<"This is score class"<<endl;
    }

};

class merges: public score, public player{
public:
        test()
    {
        cout<<"this is merges class"<<endl;
    }

};

int main()
{
    merges a;
    a.test();
    a.putsdata();
    a.putdata();
    a.display();

}


