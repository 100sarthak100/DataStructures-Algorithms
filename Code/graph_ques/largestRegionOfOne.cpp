// Input:
// 2
// 3 3
// 1 1 0 0 0 1 1 0 1
// 1 3
// 1 1 1

// Output:
// 4
// 3

// 1 1 0
// 0 0 1
// 1 0 1

// Largest region of 1s in the above matrix is with total 4 1s 



bool isValid(int g[][SIZE], bool ** visited, int i, int j, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m 
    && g[i][j] == 1 && !visited[i][j]);
}


void dfs(int g[][SIZE], bool** visited, int i, int j, int &maxArea, int n, int m)
{
    static int dx[] = {-1,-1,1,1,0,-1,0,1};
    static int dy[] = {-1,1,-1,0,1,0,-1,1};
    
    visited[i][j] = true;
    maxArea++;
    for(int p = 0; p < 8; p++)
    {
        if(isValid(g, visited, i + dx[p], j + dy[p], n, m))
        {
            dfs(g, visited, i + dx[p], j + dy[p], maxArea, n, m);
        }
    }
}

int findMaxArea(int n, int m, int g[SIZE][SIZE] )
{
    bool** visited = new bool *[n+1];
    for(int i = 0;i <= n;i++)
        visited[i] = new bool [m+1];
    for(int i = 0;i<=n;i++)
        for(int j =0;j<=m;j++)
            visited[i][j] = false;
    
    int maxArea = 0;
    int maxA = INT_MIN;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(g[i][j] == 1 && !visited[i][j])
            {
                dfs(g, visited, i, j, maxArea, n, m);
                maxA = max(maxArea, maxA);
                maxArea = 0;
            }
        }
    }
    return maxA;
}