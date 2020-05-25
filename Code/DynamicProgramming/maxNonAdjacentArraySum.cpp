// Given an array of integers, find the subset of non-adjacent elements with the maximum sum

//     Sample Input
//     5 3 5 -7 8 10
//  Sample Output 2
//     15
//     Explanation 2

//     Our subsets are and.The maximum subset sum is from the fifth subset listed.

int maxSubsetSum(vector<int> arr)
{
    int n = arr.size();
    int dp[n];
    dp[0] = arr[0];
    if (arr[1] < arr[0])
        dp[1] = arr[0];
    else
        dp[1] = arr[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = maxNum(arr[i], dp[i - 1], arr[i] + dp[i - 2]);
    }
    return dp[n - 1];
}
