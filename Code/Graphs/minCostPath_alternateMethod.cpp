#include <bits/stdc++.h>
using namespace std;
#define MAX 50

bool isValid(int row, int col, int ROW, int COL)
{
    return (row >= 0) && (col >= 0) && (row < ROW) && (col < COL);
}

int shortest(int a[MAX][MAX], int n, int m)
{
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    map<pair<int, int>, int> dist;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[make_pair(i, j)] = INT_MAX;

    set<pair<int, pair<int, int>>> s;
    s.insert(make_pair(a[0][0], make_pair(0, 0)));
    dist[make_pair(0, 0)] = a[0][0];
    while (!s.empty())
    
    {
        pair<int, pair<int, int>> p = *s.begin();
        int weight = p.first;
        pair<int, int> coordinate = p.second;
        s.erase(s.begin());
        for (int i = 0; i < 4; ++i)
        {
            int xset = coordinate.first + dx[i];
            int yset = coordinate.second + dy[i];

            if (isValid(xset, yset, n, m))
            {
                if (dist[make_pair(xset, yset)] > weight + a[xset][yset])
                {
                    auto l = s.find(make_pair(dist[make_pair(xset, yset)], make_pair(xset, yset)));
                    if (l != s.end())
                        s.erase(l);
                    s.insert(make_pair(weight + a[xset][yset], make_pair(xset, yset)));
                    dist[make_pair(xset, yset)] = weight + a[xset][yset];
                }
            }
        }
    }
    return dist[make_pair(n - 1, m - 1)];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int a[MAX][MAX];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << shortest(a, n, n) << endl;
    }
}
