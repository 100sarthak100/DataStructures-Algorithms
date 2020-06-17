// Given a m x n matrix, if an element is 0, set its entire row and 
// column to 0. Do it in-place.

// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]

// Example 2:

// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]

// time - O(N*M)
// space - O(1)

// best soln
class Solution {
public:
    #define flag 'c'
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<n; k++)
                    {
                        if(matrix[k][j] == 0 || matrix[k][j] == flag)
                            continue;
                        else matrix[k][j] = flag;
                    }
                    
                    for(int k=0; k<m; k++)
                    {
                        if(matrix[i][k] == 0 || matrix[i][k] == flag)
                            continue;
                        else matrix[i][k] = flag;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == flag)
                    matrix[i][j] = 0;
            }
        }
    }
};