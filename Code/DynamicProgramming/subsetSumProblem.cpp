// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output: True  
// There is a subset (4, 5) with sum 9.

// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
// Output: False
// There is no subset that add up to 30.

// set[]={3, 4, 5, 2}
// target=6
 
//     0    1    2    3    4    5    6

// 0   T    F    F    F    F    F    F

// 3   T    F    F    T    F    F    F
     
// 4   T    F    F    T    T    F    F   
      
// 5   T    F    F    T    T    T    F

// 2   T    F    T    T    T    T    T

// Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
// Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.

#include <bits/stdc++.h>
using namespace std;

// recursion
// bool subsetSum(int arr[], int n, int sum)
// {
//     if(sum == 0)
//         return true;

//     if(n == 0 && sum != 0)
//         return false;

//     if(arr[n-1] > sum)
//         return subsetSum(arr, n-1, sum);

//     return subsetSum(arr, n-1, sum) || subsetSum(arr, n-1, sum - arr[n-1]);
// }


// dp
bool subsetSum(int arr[], int n, int sum)
{
    bool dp[n+1][sum+1];

    for(int i = 0;i<=n;i++)
        dp[i][0] = true;

    for(int i = 1; i<=sum; i++)
        dp[0][i] = false;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=sum; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;

    if(subsetSum(arr, n, sum))
        cout<<"subset present"<<endl;
    else cout<<"not present"<<endl;
}