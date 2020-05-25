#include <bits/stdc++.h>
using namespace std;

//  For example if m is 4, the person can climb 1 stair or 2 stairs or
// 3 stairs or 4 stairs at a time
// ways(n, m) = ways(n-1, m) + ways(n-2, m) + ... ways(n-m, m)
// order matters

int countWaysUtil(int n, int m)
{
    int res[n];
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        res[i] = 0;
        for (int j = 1; j <= m && j <= i; ++j)
            res[i] += res[i - j];
    }
    return res[n - 1];
}

int countWays(int s, int m)
{
    return countWaysUtil(s + 1, m);
}

int main()
{
    int s = 4; // strairs;
    int m = 2; // ways
    cout << countWays(s, m) << endl;
}