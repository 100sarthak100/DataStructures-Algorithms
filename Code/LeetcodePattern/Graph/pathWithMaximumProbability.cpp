// You are given an undirected weighted graph of n nodes (0-indexed), 
// represented by an edge list where edges[i] = [a, b] is 
// an undirected edge connecting the nodes a and b with a probability 
// of success of traversing that edge succProb[i].

// Given two nodes start and end, find the path with the maximum 
// probability of success to go from start to end and return its 
// success probability.

// If there is no path from start to end, return 0. Your answer 
// will be accepted if it differs from the correct answer by at 
// most 1e-5.

// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], 
// start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a 
// probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = 
// [0.5,0.5,0.3], start = 0, end = 2
// Output: 0.30000

// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, 
// end = 2
// Output: 0.00000
// Explanation: There is no path between 0 and 2.

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> adj(n+1);
        for(int i=0; i<edges.size(); i++)
        {
            auto v = edges[i];
            adj[v[0]].push_back({succProb[i], v[1]});
            adj[v[1]].push_back({succProb[i], v[0]});
        }
        
        vector<bool> visited(n+1, false);
        
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({1, start});
        vector<double> dist(n+1, 0.000);
        dist[start] = 1;
        
        while(!pq.empty())
        {
            pair<double, int> p = pq.top();
            pq.pop();
            
            double w = p.first;
            int x = p.second;
            if(visited[x])
                continue;
            
            visited[x] = true;
            
            for(int i=0; i<adj[x].size(); i++)
            {
                auto newNode = adj[x][i];
                if(dist[newNode.second] < newNode.first * dist[x])
                {
                    dist[newNode.second] = newNode.first * dist[x];
                    pq.push({dist[newNode.second], newNode.second});
                }
            } 
        }
        for(int i=0; i<=n; i++)
            cout<<dist[i]<<" ";
        return dist[end];
    }
};