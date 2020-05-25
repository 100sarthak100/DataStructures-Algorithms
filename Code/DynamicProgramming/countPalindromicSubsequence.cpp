// returns an integer denoting the no of palindromic subsequence (need not necessarily be distinct) which 
// could be formed from the string str.

// Input:
// 2
// abcd
// aab

// Output:
// 4
// 4

// Explanation:
// For the first test case
// palindromic subsequence are : "a" ,"b", "c" ,"d"

// 1 2 3 4 0 
// 0 1 2 3 4 
// 0 0 1 2 3 
// 2 0 0 1 2 
// 1 4198139 0 0 1 


// For second test case
// palindromic subsequence are :"a", "a", "b", "aa"

int countPS(string str)
{
   int n = str.length();
   int dp[n+1][n+1];
   for(int i = 0;i<=n;i++)
   {
       for(int j =0;j<=n;j++)
       {
           if(i == j)
            dp[i][j] = 1;
            else dp[i][j] = 0;
       }
   }
   int k;
   for(int l=2; l<=n;l++)
   {
       for(int i=0;i<n;i++)
       {
            k = l + i - 1;
            if(str[i] == str[k])
                dp[i][k] = 1 + dp[i+1][k] + dp[i][k-1];
            else
                dp[i][k] = dp[i+1][k] + dp[i][k-1] - dp[i+1][k-1];
       }
   }
   return dp[0][n-1];
}