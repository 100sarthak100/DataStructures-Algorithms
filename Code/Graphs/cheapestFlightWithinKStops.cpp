// important
// There are n cities connected by m flights. Each flight starts 
// from city u and arrives at v with a price w.

// Now given all the cities and flights, together with starting 
// city src and the destination dst, your task is to find the 
// cheapest price from src to dst with up to k stops. 
// If there is no such route, output -1.

// Example 1:
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

// using dfs + prunning
// prunning - breaking the loop when the totalCost > fare
class Solution {
public:
    void solve(vector<vector<int>>& adj, vector<vector<int>>& cost, int src, int dst, int k, int& fare, int totalCost, vector<bool>& visited)
    {
        if(k < -1)
            return;
        
        if(src == dst)
        {
            fare = min(fare, totalCost);
            return;
        }
        
        visited[src] = true;
        
        for(int i = 0; i< adj[src].size(); i++)
        {
            if(!visited[adj[src][i]] && (totalCost + cost[src][adj[src][i]] <= fare))
                solve(adj, cost, adj[src][i], dst, k-1, fare, totalCost + cost[src][adj[src][i]], visited);
        }
        
        visited[src] = false;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1, vector<int>(n+1));
        
        for(int i = 0; i<flights.size(); i++)
        {
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        vector<bool> visited(n+1, false);
        
        int fare = INT_MAX;
        
        solve(adj, cost, src, dst, K, fare, 0, visited);
        
        if(fare == INT_MAX)
            return -1;
        else return fare;
    }
};

// same above method but with just a vector with pairs
class Solution {
public:
    void solve(vector<vector<pair<int, int>>>& adj, int src, int dst, int k, int& fare, int totalCost, vector<bool>& visited)
    {
        if(k < -1)
            return;
        if(src == dst)
        {
            fare = min(fare, totalCost);
            return;
        }
        
        visited[src] = true;
        for(int i = 0; i< adj[src].size(); i++)
        {
            if(!visited[adj[src][i].first] && (totalCost + adj[src][i].second <= fare))
                solve(adj, adj[src][i].first, dst, k-1, fare, totalCost + adj[src][i].second, visited);
        }
        
        visited[src] = false;
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       vector<vector<pair<int, int>>> adj(n);
        for(auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});
        
        vector<bool> visited(n+1, false);
        int fare = INT_MAX;
        solve(adj, src, dst, K, fare, 0, visited);
        
        if(fare == INT_MAX)
            return -1;
        else return fare;
    }
};

// another method diskstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int>& f : flights)
            adj[f[0]].push_back({f[1], f[2]});
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src, K+1});
        
        while(!q.empty())
        {
            vector<int> temp = q.top();
            q.pop();
            int d = temp[0];
            int u = temp[1];
            int e = temp[2];
            
            if(u == dst)
                return d;
            
            if(e > 0)
            {
                for(pair<int, int>& p : adj[u])
                    q.push({d + p.second, p.first, e-1});
            }
        }
        return -1;
    }
};

// bfs using simple queue
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
    //1. Create an Adjacency List
        vector<vector<vector<int>>> adjList(n);
        
        //example :
        //0 : {1, 100}, {2, 500}
        //1 : {2, 100}
        //2 : 
        
        for(auto f : flights) {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            adjList[from].push_back({to, cost});
            //from : source
            //to : dest 
            //cost: cost from 'from' to 'to'
        }
        
    //2. Create a queue for performing BFS
        queue<vector<int>> q;
        
     //3. Push source in q as {src, money spent so far, number of stops b/w current city and source}
        q.push({src, 0, -1});
        //Note : if {A, B} are two directly connected cities, then number of stops b/w them is Zero,
        //so for convenience i'm assuming number of stops b/w A and A as -1
        
     int minCost = INT_MAX;   //this keeps track of minimum cost
    
     while(!q.empty()) {
            vector<int> curStation = q.front(); 
            q.pop();
         
            int curCity = curStation[0];
            int curCost = curStation[1];
            int curK = curStation[2];      //this is the number of stops seen so far from source to current city
         
            if(curCity == dst) {
              minCost = min(minCost, curCost);
              continue;  
            }
             
            for(auto p : adjList[curCity]) {
                //we include a city in our route only if :
                // > it doesn't exceed number of stops alloted
                // > it keeps cost less than mincost
				//***
                if(curK+1 <= k and curCost + p[1] < minCost)
                q.push({p[0], p[1] + curCost, curK+1});
            } 
     }   
     return minCost==INT_MAX?-1:minCost;   
    }
	