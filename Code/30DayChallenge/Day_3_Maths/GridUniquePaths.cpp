// A robot is located at the top-left corner of a m x n grid 
// (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in 
// time. The robot is trying to reach the bottom-right corner of 
// the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// Example 1:

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach 
// the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
// Example 2:

// Input: m = 7, n = 3
// Output: 28

// dp solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                dp[i][j] = 1;
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        
        return dp[m-1][n-1];
    }
};

// using recursion
int Solution::uniquePaths(int A, int B) {
if(A<1 || B<1) return 0;
if(A==1 && B==1) return 1;
return uniquePaths(A-1,B)+uniquePaths(A,B-1);
}

// unique path with obstacles

// Example 1:

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Time Complexity: O(M×N). The rectangular grid given to us is 
// of size M×N and we process each cell just once.
// Space Complexity: O(1). We are utilizing the obstacleGrid as 
// the DP array. Hence, no extra space.


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        obstacleGrid[0][0] = 1;
        
        for(int i=1; i<n; i++)
        {
            if(obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1)
                obstacleGrid[i][0] = 1;
            else obstacleGrid[i][0] = 0;
        }
        
        for(int i=1; i<m; i++)
        {
            if(obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1)
                obstacleGrid[0][i] = 1;
            else obstacleGrid[0][i] = 0;
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        
        return obstacleGrid[n-1][m-1];
    }
};