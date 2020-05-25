#include <bits/stdc++.h>
using namespace std;

//order doesn't matter
int hops(int n)                   // for n = 4
{                                 // 1 1 1 1
    int table[n + 1] = {0};       // 1 1 2, 1 2 1, 2 1 1
    table[0] = 1;                 //  3 1, 1 3
                                  //  2 2
    for (int i = 1; i <= n; ++i)  // output(if order matter) = 7
        table[i] += table[i - 1]; // output(if order doesn't matter) = 4

    for (int i = 2; i <= n; ++i)
        table[i] += table[i - 2];

    for (int i = 3; i <= n; ++i)
        table[i] += table[i - 3];

    return table[n];
}

// order matters
int printCountDP(int dist)
{
    int count[dist + 1];

    // Initialize base values. There is one way to cover 0 and 1
    // distances and two ways to cover 2 distance
    count[0] = 1, count[1] = 1, count[2] = 2;

    // Fill the count array in bottom up manner
    for (int i = 3; i <= dist; i++)
        count[i] = count[i - 1] + count[i - 2] + count[i - 3];

    return count[dist];
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << hops(n) << endl;
        cout << printCountDP(n) << endl;
    }
}