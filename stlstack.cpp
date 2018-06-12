#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    std::stack<int>s;
    std::stack<int>r;
    std::stack<int>e1;
    std::stack<int>e2;
    int t;
    int sum,a,i,n,b,c;
    for(t=5;t>0;t--)
    {
        s.push(t);
        std::cout<<s.top()<<endl;
    }

        std::swap(s,e1);
        std::swap(r,e2);
        std::cout<<s.top()<<e1.top();
    return 0;
}
