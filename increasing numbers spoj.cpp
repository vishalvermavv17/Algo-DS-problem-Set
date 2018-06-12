#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,temp,top=0,len;
        cin>>n;
        int arr[n+1]={0};
        arr[0]=-1;
        while(n--)
        {
            cin>>temp;
            if(temp > arr[top])
                arr[++top]=temp;
            else
            {
                int low=1,high=top;

                while(low <= high)
                {
                    int mid=(low+high)/2;
                    if(temp > arr[mid])
                        low=mid+1;
                    else
                        high=mid-1;
                }
                arr[low]=temp;
            }
        }
        cin>>len;

        if(top >= len)
            cout<<arr[len]<<"\n";
        else
            cout<<"-1\n";
    }

}
