// Given a positive integer n, break it into the sum of at least 
// two positive integers and maximize the product of those integers.
// Return the maximum product you can get.

// Example 1:

// Input: 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.
// Example 2:

// Input: 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

// same as unbounded knapsack

class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++)
        {
            for(int w=0; w<=n; w++)
            {
                if(i==0)
                    dp[i][w] = 0;
                if(w==0)
                    dp[i][w] = 1;
                // at least 2 breaksa are required
                if(i >= 1 && w>=1)
                {    
                // i*dp[i][w - i], cause we have to maximize the product
                if(i <= w)
                    dp[i][w] = max(i*dp[i][w - i], dp[i-1][w]);
                else
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n-1][n];
    }
};