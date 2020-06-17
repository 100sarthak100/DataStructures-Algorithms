// Time Complexity: O(Logn).
// Where n is the number of elements in the input array. In each step our search 
// becomes half. So it can be compared to Binary search, So the time complexity is 
// O(log n)

// Space complexity: O(1).
// No extra space is required, so the space complexity is constant.

// Index of a peak point is 2

// modified binary search
#include <bits/stdc++.h>
using namespace std;

int findPeakUtil(int arr[], int low, int high, int n)
{
    int mid = low + (high - low)/2;

    if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n-1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if(arr[mid-1] > arr[mid] && mid > 0)
        return findPeakUtil(arr, low, mid - 1, n);
    else
        return findPeakUtil(arr, mid + 1, high, n);
}

int findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}

int main()
{
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is "
         << findPeak(arr, n);
    return 0;
}