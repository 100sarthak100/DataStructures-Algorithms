// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ret;
        int row = 0;
        int col = 0;
        int rowEnd = n;
        int colEnd = m;

        while (row < rowEnd && col < colEnd)
        {
            for (int i = col; i < colEnd; i++)
            {
                ret.push_back(matrix[row][i]);
                cout << " uo " << matrix[row][i] << " ";
            }
            row++;
            for (int j = row; j < rowEnd; j++)
            {
                ret.push_back(matrix[j][colEnd - 1]);
                cout << matrix[j][colEnd - 1] << " ";
            }
            colEnd--;
            if (col < colEnd)
            {
                for (int i = colEnd - 1; i >= col; i--)
                {
                    ret.push_back(matrix[rowEnd - 1][i]);
                    cout << matrix[rowEnd - 1][i] << " ";
                }
                rowEnd--;
            }

            if (row < rowEnd)
            {
                for (int i = rowEnd - 1; i >= row; i--)
                {
                    ret.push_back(matrix[i][col]);
                    cout << matrix[i][col] << " ";
                }
                col++;
            }
        }
        // 6 is comimg in the end , remove it manually
        return ret;
    }
};