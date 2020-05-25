// A Maze is given as N*N binary matrix
// A rat starts from source and has to reach the destination
// source -> maze[0][0], destination -> maze[n-1][n-1]
// movement in all directions are possible
// Using Backtracking
// only possible way is through 1
/* Input ={ 1 0 0 0 0 }, 
          { 1 1 1 1 1 }, 
          { 1 1 1 0 1 }, 
          { 0 0 0 0 1 }, 
          { 0 0 0 0 1 }
   Output = DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int arr[][10], int n, bool visited[][10])
{
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || arr[x][y] == 0)
        return false;
    return true;
}

void printWaysUtil(int x, int y, int arr[][10], int n, string &path,
                   vector<string> &possiblePaths, bool visited[][10])
{
    // base condition
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || arr[x][y] == 0)
        return;
    if (x == n - 1 && y == n - 1)
    {
        possiblePaths.push_back(path);
        return;
    }

    visited[x][y] = true;

    // x+1 -> Down('D')
    if (isSafe(x + 1, y, arr, n, visited))
    {
        path.push_back('D');
        printWaysUtil(x + 1, y, arr, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // x - 1 -> UP ('U')
    if (isSafe(x - 1, y, arr, n, visited))
    {
        path.push_back('U');
        printWaysUtil(x - 1, y, arr, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // y+1 -> right ('R')
    if (isSafe(x, y + 1, arr, n, visited))
    {
        path.push_back('R');
        printWaysUtil(x, y + 1, arr, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // y-1 -> left ('L')
    if (isSafe(x, y - 1, arr, n, visited))
    {
        path.push_back('L');
        printWaysUtil(x, y - 1, arr, n, path, possiblePaths, visited);
        path.pop_back();
    }
    visited[x][y] = false;
}

void printWays(int arr[][10], int n)
{
    bool visited[10][10];
    string path;
    vector<string> possiblePaths;            // vector to store posiisble paths
    memset(visited, false, sizeof(visited)); // setting all the values as false
    // utility function
    // arguments -> start,end,arr,n,path,possiblePaths,visited
    printWaysUtil(0, 0, arr, n, path, possiblePaths, visited);
    // printing the possible paths
    if (possiblePaths.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < possiblePaths.size(); i++)
            cout << possiblePaths[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t; // No of test cases
    while (t--)
    {
        int n;
        cin >> n; // n*n matrix
        int arr[10][10];
        // taking inputs
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> arr[i][j];

        // maze function
        // arguments -> arr,n
        printWays(arr, n);
    }
}
