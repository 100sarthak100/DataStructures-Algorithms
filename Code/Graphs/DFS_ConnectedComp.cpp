// no of disconnected components using dfs
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(int s)
{
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (visited[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}

// void initialize()
// {
//     for (int i = 0; i < 10; ++i)
//         visited[i] = false;
// }

int main()
{
    int nodes, edges, x, y, connectedComp = 0;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //initialize();
    for (int i = 1; i <= nodes; ++i)
    {
        if (visited[i] == false)
        {
            dfs(i);
            connectedComp++;
        }
    }
    cout << "No of connected components : " << connectedComp << endl;
}