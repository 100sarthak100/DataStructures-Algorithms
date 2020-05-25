#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int s = q.front();
        cout << s << " ";
        q.pop();
        for (int i = 0; i < adj[s].size(); ++i)
        {
            if (vis[adj[s][i]] == false)
            {
                vis[adj[s][i]] = true;
                q.push(adj[s][i]);
            }
        }
    }
}

int main()
{
    int nodes, edges, x, y;
    cin >> nodes >> edges;
    vector<int> adj[2 * edges];
    bool vis[nodes] = {false};
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(0, adj, vis);
}