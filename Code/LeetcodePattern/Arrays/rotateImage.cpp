// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Given input matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Example 2:

// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 

// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

class Solution {
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<m; j++)
            {
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0, k=n-1; j<k; j++, k--)
                swap(&matrix[i][j], &matrix[i][k]);
        }
    }
};