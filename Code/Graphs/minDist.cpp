#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int dist[1001];

void dfs(int s)
{
    dist[s]++;
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (visited[adj[s][i]] == false)
        {
            dist[adj[s][i]] = dist[s];
            dfs(adj[s][i]);
        }
    }
}

int main()
{
    int n, x, y, q, l;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> q;
    dfs(1);
    cin >> l;
    map<int, int> a;
    a[l] = dist[l];
    int min = a[l];
    for (int i = 0; i < q - 1; ++i)
    {
        cin >> l;
        a[l] = dist[l];
        if (a[l] < min)
        {
            min = a[l];
        }
    }
    for (auto x : a)
    {
        if (x.second == min)
        {
            cout << x.first << endl;
            break;
        }
    }
}
