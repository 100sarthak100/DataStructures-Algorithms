// Input:
// 2
// 6
// 5 5 10 100 10 5
// 3
// 1 2 3
// Output:
// 110
// 4

// Explanation:
// Testcase1:
// 5+100+5=110
// Testcase2:
// 1+3=4

ll FindMaxSum(ll arr[], ll n)
{
    if(n < 2)
        return arr[0];
    ll dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2;i<=n;i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i-2]);
    }
    return dp[n-1];
}