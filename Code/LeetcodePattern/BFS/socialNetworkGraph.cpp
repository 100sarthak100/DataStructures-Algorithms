// In a social networking site, people are connected with other 
// people. The whole system appears as a giant connected graph. 
// In this question, you are required to answer the total number 
// of people connected at t nodes away from each other (t distance 
// connectivity). For example: Two persons directly connected are 
// at 1 distance connectivity. While the two persons having a common 
// contact without having direct connectivity, are at 2 distance 
// connectivity.

// First line of input line contains, two integers n and e, where 
// n is the nodes and e are the edges. Next e line will contain 
// two integers u and v meaning that node u and node v are connected 
// to each other in undirected fashion. Next line contains single 
// integer, m, which is number of queries. Next m lines, each have 
// two inputs, one as source node and other as a required t distance 
// connectivity which should be used to process query.

// input
// 9 10
// 1 2
// 2 3
// 1 7
// 2 4
// 3 4
// 4 7
// 7 8
// 9 7
// 7 6
// 5 6
// 3
// 4 2
// 5 3
// 2 1

// output
// 4
// 4
// 3

// Time - O(V + E)
// Space - O(E)

#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> adj[], int n, int src, int hop)
{
	vector<bool> visited(n+1, false);
	queue<pair<int, int>> q;
	q.push({src, 0});
	int count = 0;
	while(!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		if(visited[p.first])
			continue;

		if(p.second == hop)
			count++;
		
		visited[p.first] = true;
		for(int i=0; i<adj[p.first].size(); i++)
		{
			int x = adj[p.first][i];
			if(!visited[x])
				q.push({x, p.second+1});
		}
	}
	return count;
}

int main()
{
	int n, e;
	cin>>n>>e;
	vector<int> adj[2*e];
	int u, v;
	for(int i=0; i<e; i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int m; cin>>m;
	int src, hop;
	while(m--)
	{
		cin>>src>>hop;
		cout<<bfs(adj, n, src, hop)<<endl;
	}
}