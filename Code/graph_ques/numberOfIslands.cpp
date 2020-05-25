// only can traverse horizontally and vertically(4 directions)
// this ex is for travel in 8 directions
// // int M[][COL] = { { 1, 1, 0, 0, 0 },   char array
//                      { 0, 1, 0, 0, 1 },
//                      { 1, 0, 0, 1, 1 },
//                      { 0, 0, 0, 0, 0 },
//                      { 1, 0, 1, 0, 1 } };
// output Number of islands is: 5

class Solution
{
public:
    bool isValid(int i, int j, bool **visited, vector<vector<char>> &grid)
    {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1' && !visited[i][j]);
    }

    void dfs(vector<vector<char>> &grid, bool **visited, int x, int y)
    {
        //cout<<"inside dfs: "<<x<<" "<<y<<endl;

        static int dx[4] = {-1, 0, 0, 1};
        static int dy[4] = {0, -1, 1, 0};

        visited[x][y] = true;
        for (int p = 0; p < 4; p++)
        {
            if (isValid(x + dx[p], y + dy[p], visited, grid))
            {
                dfs(grid, visited, x + dx[p], y + dy[p]);
                //cout<<"inside for p: "<<x+dx[p]<<" "<<y+dy[p]<<endl;
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        bool **visited = new bool *[n + 1];
        for (int i = 0; i <= n; i++)
            visited[i] = new bool[m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                visited[i][j] = false;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    //cout<<i<<" "<<j<<endl;
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

// alternate method without set
bool isValid(int i, int j, bool** visited, int N)
{
    return (i >= 0 && j >= 0 && i <= N && j <= N && !visited[i][j]);
}

int minStepToReachTarget(int knightPos[], int targetPos[],int N) {
    bool** visited = new bool*[N+1];
    for(int i = 0;i<=N;i++)
        visited[i] = new bool[N+1];
    for(int i = 0;i<=N;i++)
        for(int j = 0;j<=N;j++)
            visited[i][j] = false;
            
    int level[N+1][N+1];
    memset(level, 0, sizeof(level));
            
    static int dx[] = {-2,1,-1,2,-2,-1,1,2};
    static int dy[] = {1,-2,2,-1,-1,-2,2,1};
            
            
    queue<pair<int, int>> q;
    q.push({knightPos[0], knightPos[1]});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == targetPos[0] && y == targetPos[1])
            return level[x][y];
        
        for(int p = 0; p < 8; p++)
        {
            int newX = x+dx[p];
            int newY = y+dy[p];
        
            if(isValid(newX, newY, visited, N))
            {
                level[newX][newY] = level[x][y] + 1;
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
        
    }
    return -1;
}