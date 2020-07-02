
// detect cycle undirected graph
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int v, vector<int> adj[], bool vis[], int parent)
{
    vis[v] = true;
    for (int i = 0; i < adj[v].size(); ++i)
    {
        if (vis[adj[v][i]] == false)
        {
            if (isCyclic(adj[v][i], adj, vis, v))
                return true;
        }
        else if (adj[v][i] != parent)
            return true;
    }
    return false;
}

bool isCycleUtil(vector<int> adj[], bool vis[], int nodes)
{

    for (int i = 0; i < nodes; ++i)
    {
        if (vis[i] == false)
        {
            if (isCyclic(i, adj, vis, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    int nodes, edges, x, y;
    cin >> nodes >> edges;
    vector<int> adj[2 * edges];
    bool vis[nodes] = {0};
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (isCycleUtil(adj, vis, nodes) == true)
        cout << "Cycle" << endl;
    else
        cout << "No Cycle" << endl;
}