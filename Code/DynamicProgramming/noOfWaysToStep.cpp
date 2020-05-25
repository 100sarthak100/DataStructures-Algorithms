// no  of step = 7
// can climb it by 1 2 3 4 5 6 7 steps at a time
// total ways = 44;

int stepPerms(int n)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n] % 100000000007;
}