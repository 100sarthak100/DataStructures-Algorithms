// Input:
// 2
// 6 6
// ABCDGH
// AEDFHR
// 3 2
// ABC
// AC
// Output:
// 3
// 2
// explanation in notebook

int lcs(int x, int y, string s1, string s2){
    
    int dp[x+1][y+1];
  
    for(int i =0; i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[x][y];
}