// Given an undirected graph, return true if and only if it is 
// bipartite.

// Example 1:
// Input: [[1,3], [0,2], [1,3], [0,2]]
// Output: true
// Explanation: 
// The graph looks like this:
// 0----1
// |    |
// |    |
// 3----2
// We can divide the vertices into two groups: {0, 2} and {1, 3}.

// Example 2:
// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
// Output: false
// Explanation: 
// The graph looks like this:
// 0----1
// | \  |
// |  \ |
// 3----2
// We cannot find a way to divide the set of nodes into two 
// independent subsets.

// time - O(V + E)

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, int n, vector<int> &color, int c)
    {
        if(color[node] != -1 && color[node] != c)
            return false;
        
        color[node] = c;
        
        for(auto neighbor : adj[node])
        {
            if(color[neighbor] == -1)
            {
                if(dfs(neighbor, adj, n, color, 1 - c) == false)
                    return false;
            }
            
            if(color[neighbor] != -1 && color[neighbor] != 1-c)
                return false;
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i, graph, n, color, 0) == false)
                    return false;
            }
        }
        return true;
    }
};