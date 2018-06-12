#include <bits/stdc++.h>
using namespace std;


deque <int> dq;
stack <int> s;
bool flag=true;
void back_fun()
{
    if(flag)
    {
       if(dq.empty())
        cout<<"No job for Ada?\n";
        else
        {
            cout<<dq.back()<<"\n";
            dq.pop_back();
        }
    }
    else
    {
        if(dq.empty())
        cout<<"No job for Ada?\n";
        else
        {
            cout<<dq.front()<<"\n";
            dq.pop_front();
        }
    }

}

void front_fun()
{
    if(flag)
    {
        if(dq.empty())
        cout<<"No job for Ada?\n";
        else
        {
            cout<<dq.front()<<"\n";
            dq.pop_front();
        }
    }
    else
    {
        if(dq.empty())
        cout<<"No job for Ada?\n";
        else
        {
            cout<<dq.back()<<"\n";
            dq.pop_back();
        }
    }

}

void reverse_fun()
{
    /*while(!dq.empty())
    {
        s.push(dq.front());
        dq.pop_front();
    }

    while(!s.empty())
    {
        dq.push_back(s.top());
        s.pop();
    }*/
    flag=!flag;
}

void push_back_fun( )
{
    if(flag)
    {
        int temp;
        cin>>temp;
        dq.push_back(temp);
    }
    else
    {
        int temp;
        cin>>temp;
        dq.push_front(temp);
    }

}

void toFront_fun( )
{
    if(flag)
    {
        int temp;
        cin>>temp;
        dq.push_front(temp);
    }
    else
    {
        int temp;
        cin>>temp;
        dq.push_back(temp);
    }

}



int main()
{


    int Q;
    cin>>Q;

    while(Q--)
    {
        string query;
        cin>>query;

        if(!query.compare("back"))
            back_fun();

        if(!query.compare("front"))
            front_fun();

        if(!query.compare("reverse"))
            reverse_fun();

        if(!query.compare("push_back"))
            push_back_fun();

        if(!query.compare("toFront"))
            toFront_fun();
    }
}
