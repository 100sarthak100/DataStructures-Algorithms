#include <bits/stdc++.h>
using namespace std;

// using recursion
int minAttempt(int n, int k)
{
    if (k == 0 || k == 1)
        return k;
    if (n == 1)
        return k;
    int min = INT_MAX, res;
    for (int i = 1; i <= k; ++i)
    {
        res = max(minAttempt(n - 1, i - 1), minAttempt(n, k - i));
        if (res < min)
            min = res;
    }
    return min + 1;
}

// using DP
int eggDrop(int n, int k)
{
    int eggFloor[n + 1][k + 1];
    int res;
    memset(eggFloor, 0, sizeof(eggFloor));
    for (int i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
    for (int j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=k;j++)
            cout<<eggFloor[i][j]<<" ";
        cout<<endl;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=k;j++)
            cout<<eggFloor[i][j]<<" ";
        cout<<endl;
    }
    return eggFloor[n][k];
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << eggDrop(n, k) << endl;
    }
    //Minimum number of trials in worst case with 2 eggs and 36 floors is 8
    return 0;
}

// if(totalfloors == 1 || totalfloors == 0)
//     return totalfloors

// if(totaleggs == 1)  (in worst case have to try all floors)
//     return totalfloors;

//                 floors
//             0   1   2   3   4
//         0   0   0   0   0   0   
// eggs    1   0   1   2   3   4   
//         2   0   1 
//         3   0   1 

// time complexity - O(TOTALFLOOR^2 * TOTALEGGS)
// space complexity - O(totalfloors * totaleggs)