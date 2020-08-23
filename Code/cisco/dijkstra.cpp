// 1
// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1

// o/p
// 24 3 15

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pll;
#define MAX 5000
vector<pll> adj[MAX];

void dijkstra(int src, int V, int E)
{
    if(V == 0 || E == 0)
        return;
    vector<bool> visited(MAX, false);
    vector<int> dist(MAX, INT_MAX);
    dist[src] = 0;
    multiset< pair<long long, int>> s;
    s.insert({0, src});
    while(!s.empty())
    {
        pair<long long, int> p = *s.begin();
        s.erase(s.begin());

        int x = p.second;
        if(visited[x])
            continue;
        
        visited[x] = true;
        for(int i=0; i<adj[x].size(); i++)
        {
            int xi = adj[x][i].second;
            int wi = adj[x][i].first;
            if(dist[xi] > wi + dist[x])
            {
                dist[xi] = wi + dist[x];
                s.insert({dist[xi], xi});
            }
        }
    }
    for(int i=1; i<=V; i++)
    {
        if(i == src)
            continue;
        if(dist[i] == INT_MAX)
            cout<<-1<<" ";
        else
            cout<<dist[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int a, b, w;
        for(int i=0; i<n; i++)
            adj[i].clear();
        for(int i=0; i<m; i++)
        {
            //cin>>a>>b>>w;
            scanf("%d %d %d", &a, &b, &w);
            adj[a].push_back({w, b});
            adj[b].push_back({w, a});
        }
        int s;cin>>s;
        dijkstra(s, n, m);
    }
}

/////////////// wrong
int dist[n+1];
    for(int i=0; i<n+1; i++)
        dist[i] = INT_MAX;
    
    vector<bool> visited(n, false);
    multiset<pair<int, int>> st;
    st.insert({0, s});
    while(!st.empty())
    {
        pair<int, int> p = *st.begin();
        st.erase(st.begin());

        int x = p.second;
        int w = p.first;
        if(visited[x])
            continue;
        
        visited[x] = true;

        for(auto neighbor : edges[x])
        {
            if(dist[neighbor] > w + dist[x])
            {
                dist[neighbor] = w + dist[x];
                st.insert({dist[neighbor], neighbor});
            }
        }
    }