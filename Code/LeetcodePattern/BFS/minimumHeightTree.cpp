// For an undirected graph with tree characteristics, we can 
// choose any node as the root. The result graph is then a rooted 
// tree. Among all possible rooted trees, those with minimum height
//  are called minimum height trees (MHTs). Given such a graph, 
//  write a function to find all the MHTs and return a list of their 
//  root labels.

// Example 1 :

// Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |

//         1
//        / \
//       2   3 

// Output: [1]
// Example 2 :

// Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 

// Output: [3, 4]

// somewhat like minimum spanning tree
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 0)
            return {};
        if(n == 1)
            return {0};
        
        vector<vector<int>> mp(n);
        vector<int> degree(n);
        for(auto e : edges)
        {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            //cout<<i<<" "<<degree[i]<<endl;
            if(degree[i] == 1)
                q.push(i);
        }
        
        while(n > 2)
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int node = q.front();
                q.pop();
                n--;
                
                for(auto neighbor : mp[node])
                {
                    degree[neighbor]--;
                    cout<<node<<" "<<neighbor<<" "<<degree[neighbor]<<endl;
                    if(degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        
        vector<int> ret;
        while(!q.empty())
        {
            ret.push_back(q.front());
            q.pop();
        }
        
        return ret;
    }
};