#include <iostream>

int main()
{
    long int t,n,count;
    std::cin>>t;
    while(t--)
    {
        count=0;
        std::cin>>n;
        while(n/5)
        {
            count=count+n/5;
            n=n/5;
        }
        std::cout<<count<<"\n";
    }
}
