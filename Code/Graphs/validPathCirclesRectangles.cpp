int x_cood[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_cood[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int i, int j, int x, int y, bool **visited)
{
    return (i >= 0 && j >= 0 && i <= x && j <= y && !visited[i][j]);
}

bool dfs(int i, int j, int x, int y, bool **visited)
{
    if (i == x && j == y)
        return true;
    visited[i][j] = true;
    for (int p = 0; p < 8; p++)
    {
        if (isValid(i + x_cood[p], j + y_cood[p], x, y, visited))
        {
            bool b = dfs(i + x_cood[p], j + y_cood[p], x, y, visited);
            if (b)
                return true;
        }
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    bool **visited = new bool *[A + 1];
    for (int i = 0; i <= A; i++)
        visited[i] = new bool[B + 1];

    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            for (int k = 0; k < C; k++)
            {
                if (sqrt(pow(E[k] - i, 2) + pow(F[k] - j, 2)) <= D)
                {
                    visited[i][j] = true;
                    break;
                }
            }
        }
    }
    if (visited[0][0] || visited[A][B])
        return "NO";
    return dfs(0, 0, A, B, visited) ? "YES" : "NO";
}