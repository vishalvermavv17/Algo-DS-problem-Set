//Quick Sort

#include "bits/stdc++.h"
using namespace std;

int a[100];

void quickSort(int low, int high)
{
    if(low>high)
        return;
    int pivot=low;
    for(int i=low+1; i<=high; i++)
    {
        if(a[pivot]>a[i])
        {

            int temp=a[pivot];
            a[pivot]=a[i];
            a[i]=temp;
            temp=a[pivot+1];
            a[pivot+1]=a[i];
            a[i]=temp;
            pivot++;
        }
    }
    quickSort(low, pivot-1);    quickSort(pivot+1, high);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    fr(i,n)
        cin>>a[i];

    quickSort(0,n-1);
    fr(i,n)
        cout<<a[i]<<" ";



    return 0;
}

