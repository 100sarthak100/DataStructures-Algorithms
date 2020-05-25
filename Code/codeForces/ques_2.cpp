#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, a;
        vector<long long> ret;
        cin >> n >> x;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            ret.push_back(a);
        }
        long long sum = 0, wealthy = 0;
        long long prev = 0;
        for (long long i = 0; i < n - 1; ++i)
        {
            wealthy = 0;
            for (long long j = i; j < n; j++)
            {
                sum = accumulate(ret.begin() + j, ret.end(), 0);
                cout << sum / (n - j) << " ";
                if (sum / (n - j) >= x)
                {
                    wealthy = n - j;
                }
                wealthy = max(wealthy, prev);
                prev = wealthy;
            }
        }
        cout << prev << endl;
    }
}