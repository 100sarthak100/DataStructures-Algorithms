// Input -
// 4 3
// 1 2
// 1 3
// 4 2
// 1 2 1 1
// 1
// Output -
// 1

#include <bits/stdc++.h>
#define MAX 1000003
using namespace std;
vector<int> adj[MAX];
bool visited[MAX];
int arr[MAX], c, id;

void bfs(int i)
{
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    pair<int, int> p;
    q.push({i, 0});
    visited[i] = true;

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (auto x : adj[p.first])
        {
            if (!visited[x])
            {
                if (arr[x] == id)
                {
                    c = p.second + 1;
                    return;
                }
                visited[x] = true;
                q.push({x, p.second + 1});
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> id;
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == id)
        {
            c = 1e9;
            bfs(i);
            ans = min(ans, c);
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans << endl;
}