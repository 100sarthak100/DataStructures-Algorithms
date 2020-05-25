//  minimum number of steps for the knight to move to the said point.
// Given any source point, (C, D) and destination point, (E, F) on a chess board,

int X[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int Y[] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool isValid(int i, int j, int x, int y, set<pair<int, int>> &visited)
{
    return (i >= 1 && j >= 1 && i <= x && j <= y &&
            visited.find(make_pair(i, j)) == visited.end());
}

int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({C, D});
    int level[A + 1][B + 1];
    memset(level, 0, sizeof(level));

    // int **level = new int*[A+1];
    // for(int i = 0;i<=A;i++)
    //     level[i] = new int[B+1];
    // for(int i=0;i<=A;i++)
    // {
    //     for(int j=0;j<=B;j++)
    //     {
    //         level[i][j] = 0;
    //     }
    // }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == E && y == F)
            return level[x][y];
        for (int p = 0; p < 8; p++)
        {
            int newX = x + X[p];
            int newY = y + Y[p];
            if (isValid(newX, newY, A, B, visited))
            {
                level[newX][newY] = level[x][y] + 1;
                visited.insert({newX, newY});
                q.push({newX, newY});
            }
        }
    }
    return -1;
}