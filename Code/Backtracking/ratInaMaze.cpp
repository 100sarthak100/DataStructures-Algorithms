// Input:
// 3
// 4
// 1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
// 4
// 1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
// 2
// 1 0 1 0 

// Output:
// DRDDRR
// DDRDRR DRDDRR
// -1

// Consider a rat placed at (0, 0) in a square matrix of order N*N. 
// It has to reach the destination at (n-1, n-1)
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// 0's represents blocked paths and 1 represent valid paths.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int arr[][5], int n, bool visited[][5])
{
    if (row < 0 || row >= n || col < 0 || col >= n ||
        visited[row][col] || arr[row][col] == 0)
        return false;
    return true;
}

void printPathUtil(int row, int col, int arr[][5],
                   int n, string &path, vector<string> &possiblePath, bool visited[][5])
{
    if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col] || arr[row][col] == 0)
        return;
    if (row == n - 1 && col == n - 1)
    {
        possiblePath.push_back(path);
        return;
    }
    visited[row][col] = true;

    if (isSafe(row + 1, col, arr, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, arr, n, path,
                      possiblePath, visited);
        path.pop_back();
    }
    if (isSafe(row, col - 1, arr, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, arr, n, path,
                      possiblePath, visited);
        path.pop_back();
    }
    if (isSafe(row, col + 1, arr, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, arr, n, path,
                      possiblePath, visited);
        path.pop_back();
    }
    if (isSafe(row - 1, col, arr, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, arr, n, path,
                      possiblePath, visited);
        path.pop_back();
    }
    visited[row][col] = false;
}

void printPath(int arr[][5], int n)
{
    vector<string> possiblePaths;
    string path;
    bool visited[5][5];
    memset(visited, false, sizeof(visited));
    printPathUtil(0, 0, arr, n, path, possiblePaths, visited);
    if (possiblePaths.size() == 0)
        cout << -1 << endl;
    for (int i = 0; i < possiblePaths.size(); i++)
        cout << possiblePaths[i] << " ";
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[5][5];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> arr[i][j];
        printPath(arr, n);
        cout << endl;
    }
}