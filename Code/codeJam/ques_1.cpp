#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int testC = 0;
    while (t--)
    {
        testC++;
        int n;
        cin >> n;
        int arr[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> arr[i][j];
        //trace
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    sum += arr[i][j];
            }
        }
        map<int, int> m, c;
        int countR = 0, countC = 0;
        for (int i = 0; i < n; ++i)
        {
            m.clear();
            for (int j = 0; j < n; ++j)
            {
                m[arr[i][j]]++;
                if (m[arr[i][j]] > 1)
                {
                    countR++;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            c.clear();
            for (int j = 0; j < n; ++j)
            {
                c[arr[j][i]]++;
                if (c[arr[j][i]] > 1)
                {
                    countC++;
                    break;
                }
            }
        }
        m.clear();
        c.clear();
        cout << "Case #" << testC << ": " << sum << " " << countR << " " << countC << endl;
    }
}