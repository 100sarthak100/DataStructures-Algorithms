#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p, c;
        int pprev, cprev;
        pprev = -1, cprev = -1;
        int flag = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> p >> c;
            if (p >= pprev && c >= cprev && (p >= c) && flag != 1)
            {
                pprev = p;
                cprev = c;
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}