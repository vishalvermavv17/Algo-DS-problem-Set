#include <bits/stdc++.h>
#include <algorithm>
int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
        a[i]=10-i;
    std::sort(a,a+10);
    for(i=0;i<10;i++)
        std::cout<<a[i]<<"\n";

    if (!std::binary_search(a,a+10,15))
        std::cout<<"find it!"<<std::binary_search(a,a+10,15);
    return 0;
}
