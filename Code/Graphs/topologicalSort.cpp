#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<int> adj[], bool vis[], stack<int> &s)
{
    vis[v] = true;
    s.push(v);
    for (int i = 0; i < adj[v].size(); ++i)
    {
        if (vis[adj[v][i]] == false)
            topologicalSortUtil(adj[v][i], adj, vis, s);
    }
}

void topologicalSort(int nodes, vector<int> adj[])
{
    stack<int> s;
    bool vis[nodes] = {false};

    for (int i = 0; i < nodes; ++i)
    {
        if (vis[i] == false)
            topologicalSortUtil(i, adj, vis, s);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int t, nodes, edges, x, y;
    cin >> t;
    while (t--)
    {
        cin >> nodes >> edges;
        vector<int> adj[2 * edges];
        for (int i = 0; i < edges; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        topologicalSort(nodes, adj);
    }
}