#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n>0)
    {
        do
        {
            stack <int> s,temp;
            int h[1001]={0};

            int a[n],arr[n];

            for(int i=0; i<n; i++)
            {
                cin>>a[i];
                arr[i]=a[i];
                h[a[i]]++;
            }

            sort(arr,arr+n);

            //for(int i=0; i<n; i++)
            //{
              //  cout<<arr[i]<<" ";
            //}
            for(int i=n-1; i>=0; i--)
                temp.push(arr[i]);

            //int mobile_no=1;

            for(int i=0; i<n; i++)
            {
                if(a[i]==temp.top())//mobile_no)
                    temp.pop();//mobile_no++;
                else
                {
                    while(!s.empty() && s.top()==temp.top())//mobile_no)
                    {
                        s.pop();
                        temp.pop();//mobile_no++;
                    }
                     s.push(a[i]);
                }

            }
            while(!s.empty())
            {
                if(s.top()==temp.top())//mobile_no)
                {
                    temp.pop();//mobile_no++;
                    s.pop();
                }
                else
                    break;
            }
            if(s.empty())
                cout<<"yes\n";
            else
                cout<<"no\n";

            cin>>n;
        }while(n>0);
    }


}
