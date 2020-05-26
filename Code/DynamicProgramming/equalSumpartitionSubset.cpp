#include <bits/stdc++.h>
using namespace std;

// recursion
// Time Complexity: O(2^n)
// bool isSubsetSum(int arr[], int n, int sum)
// {
//     if(sum == 0)
//         return true;
//     if(n == 0 && sum != 0)
//         return false;

//     if(arr[n-1] > sum)
//         return isSubsetSum(arr, n-1, sum);

//     return isSubsetSum(arr, n-1, sum) ||
//             isSubsetSum(arr, n-1, sum - arr[n-1]);
// }

// bool findPartiion(int arr[], int n)
// {
//     int sum = 0;
//     for(int i = 0; i < n; i++)
//         sum += arr[i];
    
//     if(sum%2 != 0)
//         return false;
    
//     return isSubsetSum(arr, n, sum/2);
// }

// dp
// Time Complexity: O(sum*n)
// Auxiliary Space: O(sum*n)
// 1 1 1 1 1 1 1
// 0 0 1 1 1 1 1
// 0 0 0 1 1 1 1
// 0 1 1 1 1 1 1
// 0 0 1 1 1 1 1
// 0 0 0 1 1 1 1

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    if(sum%2 != 0)
        return false;
    
    bool dp[sum/2 + 1][n+1];

    for(int i = 0; i <= n; i++)
        dp[0][i] = true;
    
    for(int i = 1; i <= sum/2; i++)
        dp[i][0] = false;
    
    for(int i = 1; i <= sum/2; i++)
    {
        for(int j = 1; j<=n ; j++)
        {
            dp[i][j] = dp[i][j-1];
            if(i >= arr[j-1])
            {
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                dp[i][j] = dp[i][j] || dp[i - arr[j-1]][j-1];
                //cout<<arr[j-1]<<" "<<dp[i- arr[j-1]][j-1]<<endl;
            }
        }
    }
    for(int i = 0; i<=sum/2; i++)
    {
        for(int j = 0; j<=n; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[sum/2][n];
}

int main()
{
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}