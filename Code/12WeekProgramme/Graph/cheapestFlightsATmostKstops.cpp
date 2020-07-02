// There are n cities connected by m flights. Each flight starts 
// from city u and arrives at v with a price w.

// Now given all the cities and flights, together with starting 
// city src and the destination dst, your task is to find the 
// cheapest price from src to dst with up to k stops. 
// If there is no such route, output -1.


// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200

// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500

// time - O(V + E), E can range from V to V^2

class Solution {
public:
    void solve(vector<vector<pair<int, int>>> &adj, int src, int dst, int k, vector<bool> &visited, int totalCost, int &fare)
    {
        if(k < -1)
            return;
        
        if(src == dst)
        {
            fare = min(fare, totalCost);
            return;
        }
        
        visited[src] = true;
        for(int i=0; i<adj[src].size(); i++)
        {
            if(!visited[adj[src][i].first] && (totalCost + adj[src][i].second <= fare))
            {
                solve(adj, adj[src][i].first, dst, k-1, visited, totalCost + adj[src][i].second , fare);
            }
        }
        visited[src] = false;
        return;
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});
        
        vector<bool> visited(n+1, false);
        int fare = INT_MAX;
        solve(adj, src, dst, K, visited, 0, fare);
        if(fare == INT_MAX)
            return -1;
        else
            return fare;
    }
};