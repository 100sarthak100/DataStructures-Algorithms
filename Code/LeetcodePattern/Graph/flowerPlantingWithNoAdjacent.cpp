// You have N gardens, labelled 1 to N.  In each garden, 
// you want to plant one of 4 types of flowers.

// paths[i] = [x, y] describes the existence of a bidirectional 
// path from garden x to garden y.

// Also, there is no garden that has more than 3 paths coming into 
// or leaving it.

// Your task is to choose a flower type for each garden such that, 
// for any two gardens connected by a path, they have different types 
// of flowers.

// Return any such a choice as an array answer, where answer[i] is 
// the type of flower planted in the (i+1)-th garden.  The flower 
// types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

// Example 1:

// Input: N = 3, paths = [[1,2],[2,3],[3,1]]
// Output: [1,2,3]
// Example 2:

// Input: N = 4, paths = [[1,2],[3,4]]
// Output: [1,2,1,2]
// Example 3:

// Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
// Output: [1,2,3,4]

class Solution {
public:
    vector<int> colorGraph(vector<vector<int>> &adj, int N)
    {
        vector<int> color(N, -1);
        
        for(int i=1; i<=N; i++)
        {
            vector<bool> color_used(4, false);
            
            for(auto v : adj[i])
            {
                if(color[v-1] != -1)
                    color_used[color[v-1]-1] = true;
            }
            
            for(int c = 0; c<4; c++)
            {
                if(color_used[c] == false)
                {
                    color[i-1] = c + 1;
                    break;
                }
            } 
        }
        return color;
    }
   
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int n = paths.size();
        if(N == 0)
            return {};
        if(N == 1)
            return {1};
        
        vector<vector<int>> adj(N+1);
        for(int i=0; i<paths.size(); i++)
        {
            auto vec = paths[i];
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        return colorGraph(adj, N);
    }
};