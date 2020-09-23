
//Kosaraju's

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