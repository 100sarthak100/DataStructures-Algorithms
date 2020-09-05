// You are standing at position 1. From position i, you can walk 
// to i+1 or i-1 with cost 1. From position i, you can travel to 
// without any cost to Pi (p is a permutation of numbers 1...n). You have 
// to reach position n. 
// Determine the minimum possible cost.

// input -
// 6
// 6
// 1 4 3 2 5 6
// 6
// 3 2 6 5 4 1
// 6
// 3 6 2 4 1 5
// 6
// 5 4 6 3 2 1
// 6
// 1 6 5 4 2 3
// 6
// 5 1 3 6 2 4

// output -
// 3
// 0
// 0
// 0
// 1
// 1

#include <bits/stdc++.h>
using namespace std;

int bfs(int arr[], int n)
{
	int dist[n+1];
	for(int i=2; i<=n; i++)
		dist[i] = INT_MAX;
	dist[1] = 0;
	
	deque<int> q;
	q.push_back(1);
	while(!q.empty())
	{
		int p = q.front();
		q.pop_front();

		for(int i=-1; i<2; i+=2)
		{
			int x = p + i;
			if(x>0 && x<=n && dist[x] > dist[p] + 1)
			{
				dist[x] = dist[p] + 1;
				q.push_back(x);
			}
		}
		if(dist[arr[p]] > dist[p])
		{
			dist[arr[p]] = dist[p];
			q.push_front(arr[p]);
		}
	}
	return dist[n];
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int arr[n+1];
		for(int i=1; i<=n; i++)
			cin>>arr[i];
		cout<<bfs(arr, n)<<endl;
	}
}