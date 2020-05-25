#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long n, ic;
    vector<long long> a;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> ic;
            a.push_back(ic);
        }
        long long countm = 0, countp = 0;
        long long m = 0, p = 0, k = n, j = 0;
        while (j < k)
        {
            if (m <= p)
            {
                m += (a[j]);
                countm++;
                j++;
            }
            else if (m > p)
            {
                p += 2 * a[k - 1];
                countp++;
                k--;
            }
        }
        cout << countm << " " << countp << endl;
        if (countm > countp)
            cout << "Motu" << endl;
        else if (countm < countp)
            cout << "Patlu" << endl;
        else
            cout << "Tie" << endl;
    }
}