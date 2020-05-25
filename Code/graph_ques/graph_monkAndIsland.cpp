#include <bits/stdc++.h>
using namespace std;

long BFS(long s, long n, vector<long> adj[])
{
    bool vis[100001] = {0};
    long level[100001] = {0};
    long count = 0;
    level[s] = 1;
    vis[s] = true;
    queue<long> q;
    q.push(s);
    while (!q.empty())
    {
        long p = q.front();
        q.pop();
        for (long i = 0; i < adj[p].size(); ++i)
        {
            if (vis[adj[p][i]] == false)
            {
                vis[adj[p][i]] = true;
                level[adj[p][i]] = level[p] + 1;
                q.push(adj[p][i]);
            }
        }
    }

    count = level[n] - 1;
    return count;
}

int main()
{
    long x, y, t, n, m;
    cin >> t;
    for (long i = 0; i < t; ++i)
    {
        cin >> n >> m;
        vector<long> adj[n + 1];
        for (long j = 0; j < m; ++j)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        long a = BFS(1, n, adj);
        cout << a << endl;
    }
}