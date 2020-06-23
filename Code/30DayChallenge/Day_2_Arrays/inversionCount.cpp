// input
// 2  
// 5  
// 1 1 1 2 2  
// 5  
// 2 1 3 1 2

// output
// 0  
// 4 

// Time Complexity: O(n log n), The algorithm used is divide 
// space O(1)

// use this method for both merge sort and inversion count
#include <bits/stdc++.h>
using namespace std;

long long merge(int arr[], int temp[], int l, int m, int h)
{
    int i = l;
    int j = m;
    int k = l;
    long long inv_count = 0;

    while(i <= m - 1 && j <= h)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++]; 
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (m - i);
        }
    }

    while(i  <= m - 1)
        temp[k++] = arr[i++];
    while(j <= h)
        temp[k++] = arr[j++];

    for(int i = l; i<=h; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int l, int h)
{
    long long inv_count = 0;
    if(l < h)
    {
        int m = (l + h)/2;

        inv_count += mergeSort(arr, temp, l, m);
        inv_count += mergeSort(arr, temp, m+1, h);

        inv_count += merge(arr, temp, l, m+1, h);
    }
    return inv_count;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        int temp[n];
        cout<<mergeSort(arr, temp, 0, n-1)<<endl;
        // for(int i = 0; i< n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
    }
    return 0;
}
