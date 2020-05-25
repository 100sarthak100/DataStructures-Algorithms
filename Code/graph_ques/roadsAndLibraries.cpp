// Complete the function roadsAndLibraries in the editor below. It must return the minimal cost of providing libraries to all, as an integer.
// input -
// 2
// 3 3 2 1
// 1 2
// 3 1
// 2 3
// 6 6 2 5
// 1 3
// 3 4
// 2 4
// 1 2
// 2 3
// 5 6
// output -
// 4
// 12

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
long nodes;

void DFS(int n)
{
    nodes++;
    visited[n] = true;
    for (vector<int>::iterator i = adj[n].begin(); i != adj[n].end(); i++)
    {
        if (!visited[*i])
            DFS(*i);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        long c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        long cost = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                nodes = 0;
                DFS(i);
                cost = cost + c_lib;
                if (c_lib > c_road)
                    cost = cost + (c_road * (nodes - 1));
                else
                    cost = cost + (c_lib * (nodes - 1));
            }
        }
        cout << cost << endl;
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
    }
}