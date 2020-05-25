#include <bits/stdc++.h>
using namespace std;

vector<long> adj[100001];
bool vis[100001];
long level[100001];

long BFS(long s, long l)
{
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
                if (level[adj[p][i]] == l)
                    count++;
                q.push(adj[p][i]);
            }
        }
    }
    return count;
}

int main()
{
    long x, y, v, l;
    cin >> v;
    for (long i = 1; i < v; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> l;
    long ans = BFS(1, l);
    cout << ans << endl;
}