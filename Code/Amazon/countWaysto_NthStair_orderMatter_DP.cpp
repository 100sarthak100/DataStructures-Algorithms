#include <bits/stdc++.h>
using namespace std;

// order doesn't matter
// res[i-2] + 1(for 1 or 2 steps)

// for 1 or 3 steps (n/3 + 1)
long long countWays(int n) // best method
{
    return (n / 2 + 1);
}

long long countWays(int n)
{
    long long res[n + 1];
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i <= n; ++i)
        res[i] = res[i - 2] + 1;
    return res[n];
}

int main()
{
    int t;
    long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << countWays(n) << endl;
    }
}