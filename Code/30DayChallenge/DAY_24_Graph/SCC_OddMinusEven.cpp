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
    for(int i=1; i<=V; i++)
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
    
    bool *visited = new bool[V+1];
    for(int i=0; i<=V; i++)
        visited[i] = false;
    
    for(int i=1; i<=V; i++)
    {
        if(!visited[i])
            dfs(adj, visited, i, st);
    }
    
    vector<vector<int>> adjTrans = transpose(adj, V);
    for(int i=0; i<=V; i++)
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