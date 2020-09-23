// Rhezo likes to play with graphs having N nodes and M edges. 
// Lonewolf is ready 
// to give him such a graph only on one condition. He wants Rhezo to 
// find the number of critical links in the graph.

// A critical link in a graph is an edge that has the following 
// property: If we cut the link/edge, the graph will have exactly one 
// more connected component than it previously had, and the difference between the number of nodes on each side of the edge is less than a certain integer P.

// Given P and the graph, can you help Rhezo calculate the number of 
// critical links?

// Output:
// Find the number of critical links in the graph.

// Sample Input - 
// 5 4 100
// 1 2
// 2 3
// 3 4
// 4 5

// Output - 
// 4

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int low[maxn], inTime[maxn];
bool visited[maxn];
int timer = 0;
int connCompIndex[maxn] = {0};
int number[maxn] = {0};
int noofCC = 0;
int sz[maxn];
int ans = 0;
int p;

void dfsConnComp(int x)
{
    visited[x] = true;
    connCompIndex[x] = noofCC;
    number[noofCC]++;
    for(int i=0; i<adj[x].size(); i++)
    {
        if(!visited[adj[x][i]])
            dfsConnComp(adj[x][i]);
    }
}

void dfs(int i, int parent)
{
    sz[i] = 1;
    visited[i] = true;
    inTime[i] = low[i] = timer;
    timer++;

    for(auto neighbor : adj[i])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor, i);

            low[i] = min(low[i], low[neighbor]);
            sz[i] += sz[neighbor];
            if(low[neighbor] > inTime[i] && abs(sz[neighbor] - (number[connCompIndex[i]] - sz[neighbor])) < p)
                ans++;
        }
        else if(visited[neighbor] && parent != neighbor)
            low[i] = min(low[i], inTime[neighbor]);
    }
}

int main()
{
	int n, m, a, b;
    cin>>n>>m>>p;
    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            noofCC++;
            dfsConnComp(i);
        }
    }
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i, -1);
    }
    cout<<ans<<endl;
    return 0;
}