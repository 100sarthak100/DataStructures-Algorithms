// amount = 5;
// coins = [1,2,5]
// no of ways = dp[n][m] = 4

//         0   1   2   3   4   5

// []      1   0   0   0   0   0
// [1]     1   1   1   1   1   1
// [1,2]   1   1   2   2   3   3
// [1,2,5] 1   1   2   2   3   4

#include <bits/stdc++.h>
using namespace std;

void coinChange(int coin[], int arrSize, int deno)
{
    int dp[arrSize + 1][deno + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= arrSize; i++)
        dp[i][0] = 1;

    for (int row = 1; row <= arrSize; row++) // denomination required
    {
        for (int col = 1; col <= deno; col++) // size of array
        {
            if (coin[row - 1] > col)
                dp[row][col] = dp[row - 1][col];
            else
                dp[row][col] = dp[row - 1][col] + dp[row][col - coin[row - 1]];
        }
    }
    cout << dp[arrSize][deno];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    coinChange(arr, m, n);
    return 0;
}