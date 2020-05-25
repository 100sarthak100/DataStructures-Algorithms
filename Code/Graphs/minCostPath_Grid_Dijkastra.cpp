#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int x, y;
    int distance;
    cell(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

bool operator<(const cell &a, const cell &b)
{
    if (a.distance == b.distance)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.distance < b.distance);
}

bool isInsideGrid(int row, int col, int ROW, int COL)
{
    return (row >= 0) && (col >= 0) && (row < ROW) && (col < COL);
}

int shortest(int arr[][50], int n, int m)
{
    set<cell> st;

    int dis[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dis[i][j] = INT_MAX;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    st.insert(cell(0, 0, 0));
    dis[0][0] = arr[0][0];

    while (!st.empty())
    {
        cell k = *st.begin();
        st.erase(st.begin());
        for (int i = 0; i < 4; ++i)
        {
            int x = k.x + dx[i];
            int y = k.y + dy[i];

            if (!isInsideGrid(x, y, n, m))
                continue;

            if (dis[x][y] > dis[k.x][k.y] + arr[x][y])
            {
                if (dis[x][y] != INT_MAX)
                    st.erase(st.find(cell(x, y, dis[x][y])));

                dis[x][y] = dis[k.x][k.y] + arr[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << dis[i][j] << " ";
    return dis[n - 1][m - 1];
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int arr[50][50];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> arr[i][j];
        cout << shortest(arr, n, m) << endl;
    }
}