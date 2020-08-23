// Big P has recently become very famous among girls .

// Big P goes to a party and every girl present there wants to 
// dance with him. However, Big P cannot dance with all of them, 
// because there are many of them.

// Now if a girl gets to dance with Big P, she considers herself 
// to be " 1-Lucky ". A person that dances with someone who has 
// danced with a person who has danced with Big P considers 
// themselves " 2-Lucky ", and so on.

// The Luckiness is defined on the basis of above mentioned rule. 
// ( 1-Lucky -> Luckiness = 1).

// Note1: Luckiness of Big P is 0 .

// Note2: No one has negative luckiness.

// Note3: If a person's luckiness cannot be determined from the 
// above rules (he/she has not danced with anyone with finite 
// luckiness), his/her luckiness is INF (infinity).

// Note4: If a person A is not Big P himself, and has danced with 
// someone with luckiness X, and has not danced with anyone with 
// Luckiness smaller than X, then A has luckiness X+1 .

// input -
// 5 6
// 0 1
// 0 2
// 3 2
// 2 4
// 4 3
// 1 2

// output -
// 1
// 1
// 2
// 2

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int n)
{
	int dist[n+1];
	for(int i=0; i<=n; i++)
		dist[i] = INT_MAX;
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();

		for(auto neighbor : adj[p])
		{
			if(dist[neighbor] > dist[p] + 1)
			{
				dist[neighbor] = dist[p] + 1;
				q.push(neighbor);
			}
		}
	}
	for(int i=1; i<n; i++)
	{
		if(dist[i] == INT_MAX)
			cout<<-1<<endl;
		else
			cout<<dist[i]<<endl;
	}
	return;
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
	bfs(adj, n);
}