
// Time - O(log n)

#include <bits/stdc++.h>
using namespace std;

int searchArray(int arr[], int n, int k)
{
    int l = 0;
    int h = n-1;
    while(l <= h)
    {
        int mid = l + (h - l)/2;
        if(arr[mid] == k)
            return mid;
        else if(mid > l && arr[mid-1] == k)
            return mid-1;
        else if(mid < h && arr[mid+1] == k)
            return mid+1;
        
        if(arr[mid] > k)
            h = mid - 2;
        else
            l = mid + 2;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 30, 20, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 20;
    cout<<searchArray(arr, n, k);
}