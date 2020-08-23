// ou are given coins of different denominations 
// and a total amount of money amount. Write a function to 
// compute the fewest number of coins that you need to make 
// up that amount. If that amount of money cannot be made up 
// by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Note:
// You may assume that you have an infinite number of each 
// kind of coin.

// time - O(amount*coinSize)
// space - O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0)
            return -1;
        int dp[amount+1];
        for(int i=0; i<=amount; i++)
            dp[i] = amount+1;
        dp[0] = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(coins[i] > j)
                    continue;
                else
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }
        if(dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};