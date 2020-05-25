// You are given container full of water. Container can have limited amount of water.
// You also have N bottles to fill.
// You need to find the maximum numbers of bottles you can fill.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long n, x, a;
    vector<long long> c;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> x;
        for (long long j = 0; j < n; ++j)
        {
            cin >> a;
            c.push_back(a);
        }
        sort(c.begin(), c.end());
        long long sum = 0;
        long long count = 0;
        for (long long j = 0; j < n; ++j)
        {
            sum += c[j];
            if (sum > x)
                break;
            count++;
        }
        cout << count << endl;
    }
}