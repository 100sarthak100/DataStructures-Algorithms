// Given a 2D board containing 'X' and 'O' (the letter O), capture
// all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that 
// surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

// Time Complexity of the above solution is O(MN).

// using dfs
class Solution {
public:
    void dfs(vector<vector<char>>& A, int x, int y) {
        if(x >= 0 && x < A.size() && y >= 0 && y < A[0].size() && A[x][y] == 'O') {
            A[x][y] = 'P';
            dfs(A, x + 1, y);
            dfs(A, x, y + 1);
            dfs(A, x - 1, y);
            dfs(A, x, y - 1);
        } else return;
    }
    
    void solve(vector<vector<char>>& A) {
        int m = A.size();
        if(m == 0) return;
        int n = A[0].size();
        for(int i = 0; i < m; i++) {
            if(A[i][0] == 'O')
                dfs(A, i, 0);
        }
        
        for(int i = 0; i < m; i++) {
            if(A[i][n - 1] == 'O')
                dfs(A, i, n - 1);
        }
        
        for(int j = 0; j < n; j++) {
            if(A[0][j] == 'O')
                dfs(A, 0, j);
        }
        
        for(int j = 0; j < n; j++) {
            if(A[m - 1][j] == 'O')
                dfs(A, m - 1, j);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 'O')
                    A[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 'P')
                    A[i][j] = 'O';
            }
        }
    }
};