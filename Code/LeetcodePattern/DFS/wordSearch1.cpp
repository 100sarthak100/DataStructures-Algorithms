// Given a 2D board and a word, find if the word exists 
// in the grid.

// The word can be constructed from letters of sequentially 
// adjacent cell, where "adjacent" cells are those horizontally 
// or vertically neighboring. The same letter cell may not be used 
// more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

class Solution {
public:
    bool isValid(int i, int j, int n, int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
    bool dfs(vector<vector<char>> &board, int i, int j, int n, int m, int index, vector<vector<bool>> visited, string temp, string word)
    {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        visited[i][j] = true;
        temp += word[index];
        
        if(index == word.size()-1)
            return true;
        
        for(int p=0; p<4; p++)
        {
            int newx = dx[p] + i;
            int newy = dy[p] + j;
            if(isValid(newx, newy, n, m) && !visited[newx][newy])
            {
                if(board[newx][newy] == word[index+1])
                    if(dfs(board, newx, newy, n, m, index+1, visited, temp, word))
                        return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int sz = word.size();
        vector<vector<bool>> visited(n, vector<bool> (m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                visited[i][j] = false;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == word[0])
                    if(dfs(board, i, j, n, m, 0, visited, "", word))
                        return true;
            }
        }
        return false;
    }
};