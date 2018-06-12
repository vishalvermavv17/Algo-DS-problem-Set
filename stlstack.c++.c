#include <iostream>
#include <stack>

using namespace std;
int main()
{
    int s=0;
    std::stack <int> first;
    first.push_back(5);
    s=first.pop();
    std::cout<<s;
    return 0;
}
