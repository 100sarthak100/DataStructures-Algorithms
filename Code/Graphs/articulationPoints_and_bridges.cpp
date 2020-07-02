// Given an undirected graph containing N vertices and M edges, 
// find all the articulation points and all 
// the bridges in the graph

// Input:
// First line consists of two space separated integers denoting N 
// and M. M lines follow, each containing two space separated 
// integers X and Y 
// denoting there is an edge between X and Y.

// input -
// 3 2
// 0 1
// 1 2

// output -
// 1
// 1
// 2
// 0 1
// 1 2

// time - O(V + E) // dfs
// only for undirected graphs
// works for both connected and non connected graphs
// print number of articulation points 
// print all articultaion points
// print all bridges
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bridges;
int countAP = 0;
int timer = 0;

void dfs(int node, vector<vector<int>>& adj, vector<int>& low, vector<int>& order, vector<int>& parent, vector<bool>& ap, vector<bool>& visited)
{
	visited[node] = true;
	int child = 0;
	low[node] = order[node] = timer;
	timer++;

	for(int neighbor : adj[node])
	{
		if(!visited[neighbor])
		{
			child++;
			parent[neighbor] = node;

			dfs(neighbor, adj, low, order, parent, ap, visited);

			low[node] = min(low[node], low[neighbor]);

			if(low[neighbor] > order[node])
				bridges.push_back({node, neighbor});
			
			// case 1
			if(parent[node] == -1 && child > 1)
			{
				ap[node] = true;
				countAP++;
			}
			
			// case 2
			if(parent[node] != -1 && low[neighbor] >= order[node])
			{
				ap[node] = true;
				countAP++;
			}
		}
		else if(neighbor != parent[node])
			low[node] = min(low[node], order[neighbor]);
	}
}

int main()
{
	int n, m;
	cin>>n>>m;

	vector<vector<int>> adj(n);
	vector<bool> visited(n, false);
	vector<int> low(n, 0);
	vector<int> order(n, 0);
	vector<int> parent(n, -1);
	vector<bool> ap(n, false);

	for(int i=0; i<m; i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
			dfs(i, adj, low, order, parent, ap, visited);
	}

	cout<<countAP<<endl; // number of articulation points
	// print all articulation points
	for(int i=0; i<n; i++)
		if(ap[i] == true)
			cout<<i<<" ";

	cout<<endl;

	sort(bridges.begin(), bridges.end());
	cout<<bridges.size()<<endl; // number of bridges
	// print all bridges
	for(auto i : bridges)
	{
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
	}
}