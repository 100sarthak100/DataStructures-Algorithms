// a directed acyclic graph (DAG) is a graph that is directed and 
// without cycles connecting the other edges. This means that it is
// impossible to traverse the entire graph starting at one edge. 
// The edges of the directed graph only go one way. The graph is a 
// topological sorting, where each node 
// is in a certain order.

// n a directed graph, the edges are connected so that each edge 
// only goes one way. A directed acyclic graph means that the graph 
// is not cyclic, or that it is impossible to start at one point 
// in the graph and traverse the entire graph. 

// Topological sorting for Directed Acyclic Graph (DAG) is a linear 
// ordering of vertices such that for every directed edge uv, vertex 
// u comes before v in the ordering. Topological Sorting for a graph 
// is not possible if the graph is not a DAG.

// Input
// 2
// 6 6
// 5 0 5 2 2 3 4 0 4 1 1 3
// 3 4
// 3 0 1 0 2 0

// Output:
// 1
// 1

// Explanation:
// Testcase 1: The output 1 denotes that the order is valid.  So, 
// if you have implemented your function correctly, 
// then output would be 1 for all test cases

// Time Complexity: O(V+E).
// The above algorithm is simply DFS with an extra stack. 
// So time complexity is the same as DFS which is.
// Auxiliary space: O(V).
// The extra space is needed for the stack.

// dfs + stack = toposort
// only for DAG
#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<int> adj[], bool vis[], stack<int> &s)
{
    vis[v] = true;
    
    for (int i = 0; i < adj[v].size(); ++i)
    {
        if (vis[adj[v][i]] == false)
            topologicalSortUtil(adj[v][i], adj, vis, s);
    }
    s.push(v);
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