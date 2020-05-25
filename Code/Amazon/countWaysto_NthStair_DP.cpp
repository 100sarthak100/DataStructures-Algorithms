#include <bits/stdc++.h>
using namespace std;

// ways(n) = ways(n-1) + ways(n-2)
// if order matters
// ways(1) = fib(2) = 1
// ways(2) = fib(3) = 2
long int countWays(long int n)
{

    long int a = 0;
    long int b = 1;
    long int c;
    if (n == 0)
        return 0;
    for (long int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int t;
    long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << countWays(n + 1) << endl;
    }
}