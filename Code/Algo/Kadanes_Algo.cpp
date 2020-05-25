// Find the contagious subarray with maximum sum
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
    int max_soFar = arr[0];
    int max_Sum = arr[0];
    for (int i = 1; i < n; ++i)
    {
        max_Sum = max(arr[i], arr[i] + max_Sum);
        max_soFar = max(max_soFar, max_Sum);
    }
    return max_soFar;
}

int main()
{
    int t;
    cin >> t;
    long n;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << maxSum(arr, n) << endl;
    }
}