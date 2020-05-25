#include <bits/stdc++.h>
using namespace std;

// using recursion O(2^n)
int countDecoding(char *digits, int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (digits[0] == '0')
        return 0;
    int count = 0;
    if (digits[n - 1] > '0')
        count = countDecoding(digits, n - 1);
    if (digits[n - 2] == '1' ||
        (digits[n - 2] == '2' && digits[n - 1] < '7'))
        count += countDecoding(digits, n - 2);

    return count;
}

// using dp O(n)
int countDecodingDP(char *digits, int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    if (digits[0] == '0')
        return 0;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = 0;
        if (digits[i - 1] > '0')
            dp[i] = dp[i - 1];
        if (digits[i - 2] == '1' ||
            (digits[i - 2] == '2' && digits[i - 1] < '7'))
            dp[i] += dp[i - 2];
    }
    for (int i = 0; i < n; ++i)
        cout << dp[i] << " ";
    cout << endl;

    return dp[n];
}

int main()
{
    char digits[] = "1234";
    int n = strlen(digits);
    cout << "Count is " << countDecodingDP(digits, n);
}