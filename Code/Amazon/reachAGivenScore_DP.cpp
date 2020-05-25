#include <bits/stdc++.h>
using namespace std;

// if order matters {3,5} and {5,3} = 2 for n = 8
// does not care about the duplicate sets (permutation)
// int scoreComb(int n)
// {
//     if (n < 3)
//         return 0;
//     if (n == 3 || n == 5)
//         return 1;
//     return scoreComb(n - 3) + scoreComb(n - 5) + scoreComb(n - 10);
// }

// (combination)
int scoreComb(int n)
{
    int table[n + 1];
    for (int i = 0; i < n + 1; ++i)
        table[i] = 0;

    table[0] = 1;

    for (int i = 3; i <= n; ++i)
        table[i] += table[i - 3];

    for (int i = 5; i <= n; ++i)
        table[i] += table[i - 5];

    for (int i = 10; i <= n; ++i)
        table[i] += table[i - 10];

    return table[n];
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << scoreComb(n) << endl;
    }
}