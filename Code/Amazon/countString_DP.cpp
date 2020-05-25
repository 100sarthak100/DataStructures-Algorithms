// Count of strings that can be formed using a, b and c under given constraints
// Given a length n, count the number of strings of length n that can be made
// using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed

#include <bits/stdc++.h>
using namespace std;

// in O(n)
int countStrUtil(int dp[][2][3], int n, int bCount = 1, int cCount = 2)
{
    if (bCount < 0 || cCount < 0)
        return 0;
    if (n == 0)
        return 1;
    if (bCount == 0 && cCount == 0)
        return 1;

    if (dp[n][bCount][cCount] != -1)
        return dp[n][bCount][cCount];

    int res = countStrUtil(dp, n - 1, bCount, cCount);
    res += countStrUtil(dp, n - 1, bCount - 1, cCount);
    res += countStrUtil(dp, n - 1, bCount, cCount - 1);

    return (dp[n][bCount][cCount] = res);
}

int strCount(int n)
{
    int dp[n + 1][2][3];
    memset(dp, -1, sizeof(dp));
    return countStrUtil(dp, n);
}

// in O(1)
// 1 if all char a
// n if 1 char is b
// n if 1 char is c
// n(n-1) if 1 char b and 1 char c
// n(n-1)/2 id 2 char are c
// n(n-1)(n-2)/2 if 1 char b and 2 char c;
int alternateSoln(int n)
{
    return {1 + (2 * n) + 3 * (n * (n - 1)) / 2 + (n * (n - 1) * (n - 2) / 2)};
    //return 1 + (n * 2) + (n * ((n * n) - 1) / 2);
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // cout << strCount(n) << endl;
        cout << alternateSoln(n) << endl;
    }
}