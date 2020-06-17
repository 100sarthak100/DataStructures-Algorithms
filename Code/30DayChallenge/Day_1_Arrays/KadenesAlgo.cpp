#include <bits/stdc++.h>
using namespace std;

// both method works fine

// it also worked in negative array (-5 -9 -1 -2 -3) ans = -1; 
// using Dynamic Programming
// time - O(N);
// int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
// Maximum contiguous sum is 7
int maxSum(int arr[], int n)
{
    int max_soFar = arr[0];
    int max_sum = arr[0];
    for(int i = 1; i<n; i++)
    {
        max_sum = max(arr[i], arr[i] + max_sum);
        max_soFar = max(max_soFar, max_sum);
    }
    return max_soFar;
}

// works both with negative and positive arrays
// int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
// Maximum contiguous sum is 7
// Starting index 2
// Ending index 6

// time - O(N);

int maxSum2(int arr[], int n)
{
    int currMax = 0;
    int max_sofar = INT_MIN;
    int start = 0, end = 0, s = 0;

    for(int i = 0; i<n; i++)
    {
        currMax += arr[i];
        if(max_sofar < currMax)
        {
            max_sofar = currMax;
            start = s;
            end = i;
        }
        if(currMax < 0)
        {
            currMax = 0;
            s = i+1;
        }
    }
    cout<<start<<" "<<end<<endl;
    // for(int i = start; i<=end; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    return max_sofar;
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

        //cout << maxSum(arr, n) << endl;
        cout << maxSum2(arr, n) << endl;
        //cout<<maxSubarraySum(arr, n)<<endl;
    }
}