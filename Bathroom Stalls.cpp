#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream myfile;
myfile. open ("3SecondSmallOutput.txt");
    long int t;
    cin>>t;
    long int x=t;
    while(t--)
    {
        long int n,k,j=0,count=0;
        cin>>n>>k;
        vector <int> a;
        a.push_back(n);
        std::vector<int>::iterator maxi;
        while(!a.empty())
        {
            maxi=max_element(a.begin(),a.end());
            cout<<*maxi;
            n=*maxi;
            count++;
            if(count==k)
                break;
            long int mid=n/2;
            if(mid!=0)
                a.push_back(mid);
            if(n%2)
            {
                if(mid)
                    a.push_back(mid);
            }
            else
            {
                if(mid-1)
                    a.push_back(mid-1);
            }

            a.erase(maxi);

        }

        if(n%2)
            myfile<<"Case #"<<x-t<<": "<<n/2<<" "<<n/2<<endl;
        else
            myfile<<"Case #"<<x-t<<": "<<n/2<<" "<<n/2-1<<endl;
    }
    return 0;
}
            //sort(a.begin(),a.end());
//,std::greater<int>());
            /*int i,a[500000];
            for(i=0;!q.empty();i++)
            {
                a[i]=q.front();
                q.pop();
            }
            //sort(a,a+i-1,std::greater<int>());
            for(long int j=0;j<i;j++)
                q.push(a[j]);*/
