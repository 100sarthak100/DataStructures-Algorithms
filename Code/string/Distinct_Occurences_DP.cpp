// Input  : S = geeksforgeeks, T = ge
// Output : 6
// T appears in S as below three subsequences.
// [ge], [     ge], [g e], [g    e] [g     e]
// and [     g e]

#include <bits/stdc++.h>
using namespace std;

int occur(string s, string t)
{
    int m = t.length(), n = s.length();

    if (m > n)
        return 0;

    int mat[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
        mat[i][0] = 0;

    for (int j = 0; j <= n; ++j)
        mat[0][j] = 1;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (t[i - 1] != s[j - 1])
                mat[i][j] = mat[i][j - 1];
            else
                mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= m; i++, cout << endl)
        for (int j = 0; j <= n; j++)
            cout << mat[i][j] << " ";

    return mat[m][n];
}

int main()
{
    int T;
    cin >> T;
    string s, t;
    while (T--)
    {
        cin >> s >> t;
        cout << occur(s, t) << endl;
    }
}