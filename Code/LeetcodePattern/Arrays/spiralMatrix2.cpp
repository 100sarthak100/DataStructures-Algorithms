// Given a positive integer n, generate a square matrix 
// filled with elements from 1 to n2 in spiral order.

// Example:

// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

// best solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rowStart = 0, colStart = 0;
        int rowEnd = n-1, colEnd = n-1;
        int num = 1;
        vector<vector<int>> ret(n, vector<int> (n));
        
        while(rowStart <= rowEnd && colStart <= colEnd)
        {
            for(int i=colStart; i<=colEnd; i++)
            {
                ret[rowStart][i] = num;
                num++;
            }
            
            rowStart++;
            
            for(int i=rowStart; i<=rowEnd; i++)
            {
                ret[i][colEnd] = num;
                num++;
            }
            
            colEnd--;
            
            if(colStart <= colEnd)
            {
                for(int i=colEnd; i>=colStart; i--)
                {
                    ret[rowEnd][i] = num;
                    num++;
                }
                
                rowEnd--;
            }
            
            if(rowStart <= rowEnd)
            {
                for(int i=rowEnd; i>=rowStart; i--)
                {
                    ret[i][colStart] = num;
                    num++;
                }
                
                colStart++;
            }
        }
        return ret;
    }
};