#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int minCost(int arr[R][C], int m, int n)
{
    int dp[R][C];
    dp[0][0] = arr[0][0];
    //memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] + arr[i][0];
   
    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    //  for (int i = 0; i < R; i++)
    // {
    //     for (int j = 0; j < C; j++)
    //         cout << dp[i][j] << " ";
    //     cout<<endl;
    // }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[m][n];
}

int main()
{
    int cost[R][C] = {{1, 3, 1},
                      {1, 5, 1},
                      {4, 2, 1}};
    printf(" %d ", minCost(cost, 2, 2));
    return 0;
}