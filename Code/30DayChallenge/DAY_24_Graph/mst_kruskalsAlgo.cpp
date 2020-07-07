// Given a weighted, undirected and connected graph. The task is to 
// find the sum of weights of 
// the edges of the Minimum Spanning Tree.

// input -
// 4 5
// 1 2 7
// 1 4 6
// 4 2 9
// 4 3 8
// 2 3 6

// output -
// 19

// In Kruskal’s algorithm, at each iteration we will select the edge 
// with the lowest weight

// Time Complexity: O(ElogV)
// In Kruskal’s algorithm, most time consuming operation is sorting 
// because the total complexity of the Disjoint-Set operations will 
// be O(ElogV), which is the overall Time Complexity of the algorithm.

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
pair<long long, pair<int, int>> p[MAX];
int id[MAX];

void initialize()
{
	for(int i=0; i<MAX; i++)
		id[i] = i;
}

int root(int x)
{
	while(x != id[x])
	{
		id[x] = id[id[x]];
		x = id[x]; 
	}
	return x;
}

void union1(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[], int v, int e)
{
	long long cost, minimumCost = 0;

	for(int i=0; i<e; i++)
	{
		int x = p[i].second.first;
		int y = p[i].second.second;
		cost = p[i].first;

		if(root(x) != root(y))
		{
			minimumCost += cost;
			union1(x, y);
		}
	}
	return minimumCost;
}

int main()
{
	int v, e;
	cin>>v>>e;
	initialize();
	for(int i=0; i<e; i++)
	{
		int a, b, w;
		cin>>a>>b>>w;
		p[i] = make_pair(w, make_pair(a, b));
	}
	sort(p, p+e);
	long long minimumCost = kruskal(p, v, e);
	cout<<minimumCost<<endl;
}