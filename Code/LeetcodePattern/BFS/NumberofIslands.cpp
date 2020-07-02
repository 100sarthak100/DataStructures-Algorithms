class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int x, int y)
    {
        return (x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == '1');
    }
    
    void bfs(vector<vector<char>>& grid,int i, int j)
    {
        int dx[] = {-1,0, 0, 1};
        int dy[] = {0,-1, 1, 0};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int p=0; p<4; p++)
            {
                int newX = x + dx[p];
                int newY = y + dy[p];
                if(isValid(grid, newX, newY))
                {
                    q.push({newX, newY});  
                    grid[newX][newY] = '0';
                }
            }
            
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0 || m == 0)
            return 0;
        
        int island = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};

// dfs
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