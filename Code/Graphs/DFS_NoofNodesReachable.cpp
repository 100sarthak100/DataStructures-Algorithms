//the number of nodes that are unreachable from the given head node.
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool visited[100000] = {false};
int ans = 0;

int dfs(int s)
{
    ans++;
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
        }
    }
    return ans;
}

int main()
{
    int x, y, n, m, h;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> h;
    int a = dfs(h);
    cout << n - a << endl;
}