// Given weights and values of n items, put these items in a
// knapsack of capacity W to get the maximum total value in the
// knapsack.

// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3

// Example 2:

// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0

#include <bits/stdc++.h>
using namespace std;

// using recursion
// Time - O(2^N)
// Space - O(1) // although stack space is used in memory

// int knapSack(int W, int wt[], int val[], int n)
// {
//     if(n == 0 || W == 0)
//         return 0;

//     if(wt[n-1] > W)
//         return knapSack(W, wt, val, n-1);

//     else return max(val[n-1] + knapSack(W - wt[n-1], wt, val, n-1),
//                     knapSack(W, wt, val, n-1));
// }

//using dp (recurssion + memoization => Top down approach)
// Time - O(N*W)
// Space - O(1) // although stack space is used in memory

// int dp[1001][1001]; //dp[n+1][W+1]

// int knapSack(int W, int wt[], int val[], int n)
// {
//     if(n == 0 || W == 0)
//         return 0;

//     if(dp[n][W] != -1)
//         return dp[n][W];

//     if(wt[n-1] <= W)
//      return dp[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
//                 knapSack(W, wt, val, n-1));
//     else //(wt[n-1] > W)
//         return dp[n][W] = knapSack(W, wt, val, n-1);
// }

//using dp (bottom up approach => using 2d matrix)
// Time - O(N*W)
// Space - O(N*W)

int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int val[] = {2, 4, 4, 5};
    int wt[] = {4, 4, 6, 8};
    int W = 15;
    int n = sizeof(val) / sizeof(val[0]);
    // memset(dp, -1, sizeof(dp));
    cout << knapSack(W, wt, val, n) << endl;
    return 0;
}
