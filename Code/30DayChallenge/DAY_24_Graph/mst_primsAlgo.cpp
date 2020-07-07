// Given a weighted, undirected and connected graph. The task is to 
// find the sum of weights of 
// the edges of the Minimum Spanning Tree.

// a spanning tree of the graph G is a tree that spans G (that is, 
// it includes every vertex of G) and is a subgraph of G
// no of verted  = V, no of edges = V - 1

// Time Complexity: O((V+E)logV)
// The time complexity of the Prim’s Algorithm is O((V+E)logV) 
// because each vertex is inserted in the priority queue only once 
// and insertion in priority queue take logarithmic time.

// input -
// 4 5
// 1 2 7
// 1 4 6
// 4 2 9
// 4 3 8
// 2 3 6

// output -
// 19

// MST is fundamental problem with diverse applications.

// Network design.
// – telephone, electrical, hydraulic, TV cable, computer, road

// – traveling salesperson problem, Steiner tree
// - Cluster analysis

// using priority queue
// doesnot work for disconnected graphs
// It is a greedy algo
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pll;
const int MAX = 100001;
vector<pll> adj[MAX];
vector<bool> visited(MAX, false);

long long prism(int node)
{
    // min heap
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(make_pair(0, node));
	long long minimumCost = 0;

	while(!q.empty())
	{
		pll p = q.top();
		q.pop();
		int y = p.second;
		if(visited[y] == true)
			continue;
		
		visited[y] = true;
		minimumCost += p.first;

		for(int i=0; i<adj[y].size(); i++)
		{
			if(!visited[adj[y][i].second])
				q.push(adj[y][i]);
		}
	}
	return minimumCost;
}

int main()
{
	int v, e;
	cin>>v>>e;
	for(int i=0; i<e; i++)
	{
		int a, b, w;
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(w, b));
		adj[b].push_back(make_pair(w, a));
	}
	long long minimumCost = prism(1);
	cout<<minimumCost<<endl;
}
