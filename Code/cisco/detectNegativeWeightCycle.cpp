// Given a graph, the task is to check if it contains a negative 
// weight cycle or not.

// Input:
// 2
// 5 8
// 0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
// 3 3
// 0 1 -5 1 2 -6 2 0 -9
// Output:
// 0
// 1

// bellman ford algo
#include<bits/stdc++.h>
using namespace std;

#define MAX 101
vector<int> adj[MAX];

int detectNegCycle(int src, int v, int e)
{
    int dist[v+1];
    for(int i=0; i<=v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    
    for(int i=0; i<v-1; i++)
    {
        for(int j=0; j<e; j++)
        {
            if(dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]])
                dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
        }
    }
    
    for(int j=0; j<e; j++)
    {
        if(dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]])
            return 1;
    }
    return 0;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int v, e;
	    cin>>v>>e;
	    int x,y,z;
	    for(int i=0; i<e; i++)
	    {
	        cin>>x>>y>>z;
	        adj[i].clear();
	        adj[i].push_back(x);
	        adj[i].push_back(y);
	        adj[i].push_back(z);
	    }
	    cout<<detectNegCycle(0, v, e)<<endl;
	}
	return 0;
}