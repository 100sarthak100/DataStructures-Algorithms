// coins = [1,2,5]
// amount = 11
// min no of coins to make to 11 is 3 (5 + 5 + 1)

#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int arrSize, int deno)
{
    long long dp[deno + 1];
    //memset(dp, deno+1, sizeof(dp));
    for(int i = 0;i<=deno+1;i++)
            dp[i] = INT_MAX;
    dp[0] = 0;
    // for(auto i : dp)
    //         cout<<i<<" ";
    for(int i=1; i<=deno; i++)
    {
        for(int j = 0;j<arrSize;j++)
        {
            if(coins[j] > i)
                continue;
            else
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        }
        
    }
    // for(auto i : dp)
    //         cout<<i<<" ";
    return dp[deno];
}

int main()
{
    //int coins[] = {9, 6, 5, 1};
    //int coins[] = {2, 5, 3, 6};
    int coins[] = {1 ,2 ,3, 4, 5 ,6 ,7 ,8 ,9 ,10 ,11};
    int m = sizeof(coins) / sizeof(coins[0]);
    //int V = 11;
    //int V = 10;
    int V = 149;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}