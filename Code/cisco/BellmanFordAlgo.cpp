// Bellman Ford's algorithm is used to find the shortest paths from 
// the source vertex to all other vertices in a weighted graph. It 
// depends on the following concept: Shortest path contains at most  
// n - 1 edges, because the shortest 
// path couldn't have a cycle.

// A very important application of Bellman Ford is to check if there 
// is a negative cycle in the graph,

// Time Complexity of Bellman Ford algorithm is relatively high
// O(V * E) 
// in case ,E = V^2 . it is O(V^3)

// input :
// 5 5
// 1 2 5
// 1 3 2
// 3 4 1
// 1 4 6
// 3 5 5

// output i=1 to i = V
// 5 2 3 7

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
vector<int> adj[MAX];

void shortestDist(int src, int V, int E)
{
	int dist[V];
	for(int i=0; i<=V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for(int i=0; i<V-1; i++)
	{
		for(int j=0; j<E; j++)
		{
			if(dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]])
			{
				dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
				//cout<<adj[j][2]<<" "<<dist[adj[j][0]]<<endl;
			}
		}
	}

	for(int j=0; j<E; j++)
	{
		if(dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]])
		{
			cout<<"Negative cycle is present"<<endl;
			return;
		}
	}

	for(int i=2; i<=V; i++)
		cout<<dist[i]<<" ";
	cout<<endl;

	return;
}

int main()
{
	int n, m;
	cin>>n>>m;
	int a, b, w;
	for(int i=0; i<m; i++)
	{
		cin>>a>>b>>w;
		adj[i].push_back(a);
		adj[i].push_back(b);
		adj[i].push_back(w);
	}
	shortestDist(1, n, m);
}