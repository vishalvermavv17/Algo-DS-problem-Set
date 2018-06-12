#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    stack <long> s;
    long int t;
    cin>>t;

    while(t--)
    {
        int query;
        cin>>query;

        switch(query)
        {
            case 1: long int new_element;
                    cin>>new_element;
                    s.push(new_element);
                    break;
            case 2: if(!s.empty())
                        s.pop();
                    break;
            case 3: if(s.empty())
                        cout<<"Empty!\n";
                    else
                        cout<<s.top()<<"\n";
        }
    }
    return 0;
}
