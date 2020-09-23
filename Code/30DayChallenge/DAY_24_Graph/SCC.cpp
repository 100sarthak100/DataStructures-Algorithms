// Strongly Connected Components (Kosaraju's Algo)
// A directed graph is strongly connected if there is a path 
// between all pairs of vertices.
// A strongly connected component (SCC) of a directed graph is 
// a maximal strongly connected subgraph.
// We can find all strongly connected components in O(V+E) time 
// using Kosaraju’s algorithm.

// Strong Connectivity applies only to directed graphs. A directed 
// graph is strongly connected if there is a directed path from 
// any vertex to every other vertex.

// returns an integer denoting the number of strongly connected 
// components in the graph.

// number of subgraphs in which there is a path btw all pair of 
// vettex, or we can reach any node from a given node

// Input:
// 2
// 5 5
// 1 0 0 2 2 1 0 3 3 4
// 3 3
// 0 1 1 2 2 0

// Output:
// 3
// 1

// Expected Time Complexity: O(N + M). -> O(V + E)
// Expected Auxiliary Space: O(N).

// directed graph
#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<vector<int>> &adjTrans, bool visited[], int v)
{
    visited[v] = true;
    //cout<<v<<" ";
    for(int i=0; i<adjTrans[v].size(); i++)
        if(!visited[adjTrans[v][i]])
            dfsUtil(adjTrans, visited, adjTrans[v][i]);
}

vector<vector<int>> transpose(vector<int> adj[], int V)
{
    vector<vector<int>> adjTrans(V);
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
            adjTrans[adj[i][j]].push_back(i);
    }
    return adjTrans;
}

void dfs(vector<int> adj[], bool visited[], int node, stack<int> &st)
{
    visited[node] = true;
    for(int i=0; i<adj[node].size(); i++)
    {
        if(!visited[adj[node][i]])
            dfs(adj, visited, adj[node][i], st);
    }
    st.push(node);
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            dfs(adj, visited, i, st);
    }
    
    vector<vector<int>> adjTrans = transpose(adj, V);
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    int count = 0;
    int n = st.size();
    for(int i=0; i<n; i++)
    {
        int v = st.top();
        st.pop();
        if(!visited[v])
        {
            dfsUtil(adjTrans, visited, v);
            count++;
            //cout<<endl;
        }
    }
    return count;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        vector<int> adj[a];// adjaceny list can also be this ->(vector<Vector<int>> ret)
        for(int i=0; i<b; i++)
        {
            int m, n;
            cin>>m>>n;
            adj[m].push_back(n);
        }
        cout<<kosaraju(a, adj)<<endl;
    }
}

// gfg solution
void dfs(int i, stack<int>& st, vector<int> adj[], vector<bool>& visited)
{
    visited[i] = true;
    
    for(auto n : adj[i])
    {
        if(!visited[n])
            dfs(n, st, adj, visited);
    }
    st.push(i);
    return;
}

vector<vector<int>> transpose(int v, vector<int> adj[])
{
    vector<vector<int>> adjTrans(v+1);
    for(int i=0; i<v; i++)
    {
        for(auto nei : adj[i])
            adjTrans[nei].push_back(i);
    }
    return adjTrans;
}

void dfsUtil(int i, vector<vector<int>> &revAdj, vector<bool>& visited)
{
    visited[i] = true;
    for(auto nei : revAdj[i])
    {
        if(!visited[nei])
            dfsUtil(nei, revAdj, visited);
    }
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> visited(V+1, false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            dfs(i, st, adj, visited);
    }
    
    vector<vector<int>> revAdj = transpose(V, adj);
    for(int i=0; i<=V; i++)
        visited[i] = false;
    
    int count = 0;
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        if(!visited[temp])
        {
            dfsUtil(temp, revAdj, visited);
            count++;
        }
    }
    return count;
}