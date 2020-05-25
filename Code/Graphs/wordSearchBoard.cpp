// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]

// word = "ABCCED", -> returns 1,
// word = "SEE", -> returns 1,
// word = "ABCB", -> returns 1,
// word = "ABFSAB" -> returns 1
// word = "ABCD" -> returns 0

// only 4 directions are allowed
// The same letter cell may be used more than once.


int x_coord[4] = {0, 0, 1, -1};
int y_coord[4] = {-1, 1, 0, 0};

bool isValid(int i, int j, int x, int y)
{
    return (i >= 0 && j >= 0 && i < x && j < y);
}

bool dfs(int i, int j, vector<string> &A, string B)
{
    if (B.size() == 0)
        return true;
    if (A[i][j] != B[0])
        return false;
    for (int p = 0; p < 4; p++)
    {
        if (isValid(i + x_coord[p], j + y_coord[p], A.size(), A[0].size()))
        {
            bool b = dfs(i + x_coord[p], j + y_coord[p], A, B.substr(1));
            if (b)
                return true;
        }
    }
    return false;
}

int Solution::exist(vector<string> &A, string B)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (A[i][j] == B[0])
            {
                bool b = dfs(i, j, A, B);
                if (b)
                    return true;
            }
        }
    }
    return false;
}
