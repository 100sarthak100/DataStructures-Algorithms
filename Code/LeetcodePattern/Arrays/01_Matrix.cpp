// Given a matrix consists of 0 and 1, find the distance of 
// the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

// Example 1:

// Input:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]

// Output:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]
// Example 2:

// Input:
// [[0,0,0],
//  [0,1,0],
//  [1,1,1]]

// Output:
// [[0,0,0],
//  [0,1,0],
//  [1,2,1]]

class Solution {
public:
    bool isValid(int x, int y, int n,int m)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                dist[i][j] = INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        pair<int, int> p;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            for(int p=0; p<4; p++)
            {
                int newx = dx[p] + x;
                int newy = dy[p] + y;
                if(isValid(newx, newy, n, m))
                {
                    if(dist[newx][newy] > dist[x][y] + 1)
                    {
                        dist[newx][newy] = dist[x][y] + 1;
                        q.push({newx, newy});
                    }
                }
            }
            
        }
        return dist;
    }
};