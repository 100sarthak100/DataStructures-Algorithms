// Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
// Output : 5
// The longest common substring is “Geeks” and is of length 5.

// Input : X = “abcdxyz”, y = “xyzabcd”
// Output : 4
// The longest common substring is “abcd” and is of length 4.

// Input : X = “zxabcdezy”, y = “yzabcdezx”
// Output : 6
// The longest common substring is “abcdez” and is of length 6.

#include <bits/stdc++.h>
using namespace std;

int lengthCommonSubStr(string x, string y)
{
    int n = x.size();
    int m = y.size();
    int soln = -1; // variable for storing the soln
    // making a 2D array to store the length (Dynamic Programming)
    int dp[n + 1][m + 1];
    // using 2 for loops
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; j++)
        {
            // if string x or string y has length 0 than common lenth is also 0;
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;

            soln = max(soln, dp[i][j]);
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return soln;
}

int main()
{
    // t test cases
    int t;
    cin >> t;
    while (t--)
    {
        // input n and m (length of 2 strings)
        int n, m;
        cin >> n >> m;
        // input string x and y
        string x, y;
        cin >> x >> y;
        // making a function to find the length
        cout << lengthCommonSubStr(x, y) << endl;
    }
}