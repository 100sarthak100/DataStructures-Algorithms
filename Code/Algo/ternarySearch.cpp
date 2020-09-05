// Time - O(log3 N)
// Space - O(1)
#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int arr[], int n, int k)
{
    int l = 0;
    int h = n-1;
    while(l <= h)
    {
        int mid1 = l + (h - l)/3;
        int mid2 = h - (h - l)/3;
        if(arr[mid1] == k)
            return mid1;
        if(arr[mid2] == k)
            return mid2;
        
        if(k < arr[mid1])
            h = mid1 - 1;
        else if(k > arr[mid2])
            l = mid2 + 1;
        else
        {
            l = mid1 + 1;
            h = mid2 - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    cout<<ternarySearch(arr, n, k)<<endl;
}