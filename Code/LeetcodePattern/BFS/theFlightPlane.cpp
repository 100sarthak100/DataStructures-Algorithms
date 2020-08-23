// You are given flights route map of a country consisting of N 
// cities and M undirected flight routes. Each city has an airport 
// and each airport can work as layover. The airport will be in two 
// states, Loading and Running. In loading state, luggage is loaded 
// into the planes. In the running state, planes will leave the 
// airport for the next city. All the airports will switch their 
// states from Loading to Running and vice versa after every T 
// minutes. You can cross a city if its airport state is running. 
// Initially, all the airports are in running state. At an airport, 
// if its state is loading, you have to wait for it to switch its 
// state to running. The time taken to travel through any flight 
// route is C minutes. Find the lexicographically smallest path 
// which will take the minimum amount of time (in minutes) required 
// to move from city X to city Y.

// It is guaranteed that the given flight route map will be 
// connected. Graph won't contain multiple edges and self loops. 
// A self loop is an edge that connects a vertex to itself.

// input -
// 5 5 3 5
// 1 2
// 1 3
// 2 4
// 1 4
// 2 5
// 1 5

// output -
// 3
// 1 2 5 

// Fastest path will be 1->2->5. You can reach city 2 in 5 minutes. 
// After 3 minutes the airport in city 2 will change its state to 
// Loading. So in city 2, you have to wait for 1 minute for the 
// airport to change its state. So total time will be 5 minutes 
// (from city 1 to city 2) + 1 minute (waiting time at city 2) + 5 
// minutes (from city 2 to city 5) = 11 minutes.

// T and C not required if we do BFS

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int n, int x, int y)
{
	vector<bool> visited(n+1, false);
	queue<int> q;
	vector<int> parent(n+1, 0);
	q.push(x);
	bool ans = false;
	visited[x] = true;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if(ans)
			break;
		
		for(int i=0; i<adj[p].size(); i++)
		{
			int node = adj[p][i];
			if(!visited[node])
			{
				parent[node] = p;
				visited[node] = true;
				if(node == y)
				{
					ans = true;
					break;
				}
				q.push(node);
			}
		}
	}
	stack<int> st;
	// for(auto i : parent)
	// 	cout<<i<<" ";
	// cout<<endl;
	while(parent[y] != 0)
	{
		st.push(y);
		y = parent[y];
	}
	st.push(x);
	cout<<st.size()<<endl;
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return;
}

int main()
{
	int n,m,t,c;
	cin>>n>>m>>t>>c;
	vector<int> adj[2*m];
	int u, v;
	while(m--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; i++)
		sort(adj[i].begin(), adj[i].end());
	
	int x, y;
	cin>>x>>y;
	bfs(adj, n, x, y);
}