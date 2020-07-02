// Given a directed graph, check whether the graph contains a 
// cycle or not.

// Input: n = 4, e = 6
// 0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
// Output: Yes

// Input:
// 3
// 2 2
// 0 1 0 0
// 4 3
// 0 1 1 2 2 3
// 4 3
// 0 1 2 3 3 2
// Output:
// 1
// 0
// 1

// Time Complexity: O(V+E).
// Time Complexity of this method is same as time complexity of DFS 
// traversal which is O(V+E).
// Space Complexity: O(V).
// To store the visited and recursion stack O(V) space is needed.

// visited is not &visited
// giving TLE
bool isCyclicUtil(vector<int> adj[], vector<bool> visited, int curr)
{
    if(visited[curr] == true)
        return true;
        
    visited[curr] = true;
    
    bool flag = false;
    for(int i=0; i<adj[curr].size(); i++)
    {
        flag = isCyclicUtil(adj, visited, adj[curr][i]);
        if(flag == true)
            return true;
    }
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    bool flag = false;
    for(int i=0; i<V; i++)
    {
        visited[i] = true;
        for(int j=0; j<adj[i].size(); j++)
        {
            flag = isCyclicUtil(adj, visited, adj[i][j]);
            if(flag == true)
                return true;
        }
        visited[i] = false;
    }
    return false;
}

// best solution (dfs)
bool cyclic(vector<int> adj[], vector<bool> &visited, vector<bool> &inCall, int curr)
{
    visited[curr] = true;
    inCall[curr] = true;
    
    for(int i=0; i<adj[curr].size(); i++)
    {
        if(!visited[adj[curr][i]] && cyclic(adj, visited, inCall, adj[curr][i]))
            return true;
        else if(inCall[adj[curr][i]])
            return true;
    }
    inCall[curr] = false;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
   vector<bool> visited(V, false), inCall(V, false);
   
   for(int i=0; i<V; i++)
   {
       if(!visited[i])
       {
           if(cyclic(adj, visited, inCall, i))
                return true;
       }
   }
   return false;
}