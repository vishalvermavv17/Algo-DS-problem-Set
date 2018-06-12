#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;

int main()
{
    int t,n,m,i;
    unsigned long int candles;
    std::vector<long long int> v;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n>>m;
        for(i=0;i<n;i++)
        {
            std::cin>>candles;
            v.push_back(candles);
        }
        for(i=0;i<m;i++)
        {
            std::cin>>candles;
            if(std::find(v.begin(), v.end(), candles) != v.end())
            {
                std::cout<<"YES\n";
            }
            else
                std::cout<<"NO\n";
        }
        v.clear();
        candles=v.size();
        std::cout<<candles;
    }
    return 0;
}
