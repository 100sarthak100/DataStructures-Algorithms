#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool vis[10];
int level[10];

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < adj[p].size(); ++i)
        {
            if (vis[adj[p][i]] == false)
            {
                cout << p << " -> " << adj[p][i] << endl;
                cout << level[p] + 1 << endl;
                q.push(adj[p][i]);
                vis[adj[p][i]] = true;
                level[adj[p][i]] = level[p] + 1;
            }
        }
    }
}

int main()
{
    int x, y, nodes, edges;

    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    BFS(0);
}