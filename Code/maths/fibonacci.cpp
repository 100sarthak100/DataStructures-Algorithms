#include <bits/stdc++.h>
using namespace std;

void fibo(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
}

int main()
{
    int n = 10;
    fibo(n);
}