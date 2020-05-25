// Write an efficient program to find the sum of contiguous subarray within a one-dimensional
// array of numbers which has the largest sum
// array = {-2, -3, 4, -1, -2, 1, 5, -3}
// Kadane’s algorithm

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[], int n)
{
    int maxEle = arr[0];
    int currMax = arr[0];

    for (int i = 1; i < n; ++i)
    {
        currMax = max(arr[i], arr[i] + currMax);
        maxEle = max(currMax, maxEle);
    }
    return maxEle;
}

int main()
{
    int t;
    cin >> t; // for the test case
    while (t--)
    {
        int n; // size of array
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << maxSubArray(arr, n);
    }
}