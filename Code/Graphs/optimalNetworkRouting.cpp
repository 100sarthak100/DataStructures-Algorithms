#include <bits/stdc++.h>
using namespace std;
#define MAX 301

// 5 1 3 2
// 7 4 1 8
// 6 7 5 9

bool isValid(int x, int y, int n, int m)
{
    return (x>=0 && y>=0 && x<n && y<m);
}

int shortestDiff(int arr[][MAX], int n, int m)
{
    int dp[n][m];
    for(int i = 0;i<n;i++)
        for(int j = 0; j<m; j++)
            dp[i][j] = INT_MIN;
    dp[0][0] = 0;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(i == 0 && j == 0)
                continue;
            int minEle = INT_MAX;
            for(int p = 0; p<4; p++)
            {
                int newX = i + dx[p];
                int newY = j + dy[p];
                

                if(!isValid(newX, newY, n, m))
                    continue;
                if(dp[newX][newY] == INT_MIN)
                    continue;
                
                int maxEle = max(abs(arr[i][j] - arr[newX][newY]), dp[newX][newY]);
                minEle = min(minEle, maxEle);

                // cout<<i<<" "<<j<<" "<<newX<<" "<<newY<<endl;
                // cout<<maxEle<<endl;
                // cout<<endl;
            }
            //cout<<"final "<<minEle<<endl;
            dp[i][j] = minEle;
        }
    }
    // for(int i = 0;i<n; i++)
    // {
    //     for(int j = 0; j<m; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    return dp[n-1][m-1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cout << shortestDiff(arr, n, m) << endl;
}



// int getMinEffort(vector<vector<int>> C) {
//     int n = C.size();
//     int m = C[0].size();
//     int dp[n][m];
//     for(int i = 0;i<n;i++)
//         for(int j = 0; j<m; j++)
//             dp[i][j] = INT_MIN;
//     dp[0][0] = 0;

//     int dx[] = {-1, 0, 0, 1};
//     int dy[] = {0, -1, 1, 0};

    

//     for(int i = 0; i<n; i++)
//     {
//         for(int j = 0; j<m; j++)
//         {
//             if(i == 0 && j == 0)
//                 continue;
//             int minEle = INT_MAX;
//             for(int p = 0; p<4; p++)
//             {
//                 int newX = i + dx[p];
//                 int newY = j + dy[p];
                

//                 if(!isValid(newX, newY, n, m))
//                     continue;
//                 if(dp[newX][newY] == INT_MIN)
//                     continue;
                
//                 int maxEle = max(abs(C[i][j] - C[newX][newY]), dp[newX][newY]);
//                 minEle = min(minEle, maxEle);

//                 // cout<<i<<" "<<j<<" "<<newX<<" "<<newY<<endl;
//                 // cout<<maxEle<<endl;
//                 // cout<<endl;
//             }
//             //cout<<"final "<<minEle<<endl;
//             dp[i][j] = minEle;
//         }
//     }
//     // for(int i = 0;i<n; i++)
//     // {
//     //     for(int j = 0; j<m; j++)
//     //         cout<<dp[i][j]<<" ";
//     //     cout<<endl;
//     // }

//     return dp[n-1][m-1];
// }