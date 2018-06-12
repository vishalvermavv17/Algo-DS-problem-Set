#include <iostream>
#include <stack>

using namespace std;

int main()
{
    long int t,n,i,a[1000000];
    std::stack <long> s;

    std::cin>>t;
    while(t--)
    {
        i=0;
        std::cin>>n;
        s.push(i);
        std::cin>>a[0];
        std::cout<<"1";
        for(i=1;i<n;i++)
        {
            std::cin>>a[i];
            if(a[i]>=a[s.top()])
            {
                while(a[i]>=a[s.top()] && !s.empty())
                    s.pop();
            }
            if(s.empty())
                std::cout<<i+1<<" ";
            else
                std::cout<<i-s.top()<<" ";

            s.push(i);
        }
        std::cout<<"\n";
    }
    return 0;
}
