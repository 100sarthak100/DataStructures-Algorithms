// PRIM'S ALGORITHM (to find the sum of weights of edges of a 
// Minimum Spanning Tree)
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> PII;
bool marked[100000];
vector<PII> adj[100000];

//this statement means that the underlying container of the priority queue is vector<PII>(which is by default is vector<int>),
//and greater<PII> means that higher priority will be given to the smaller values.
long long mst(long long x)
{
    priority_queue<PII, vector<PII>, greater<PII>> Q; // min heap
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while (!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.second;
        if (marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for (long long i = 0; i < adj[x].size(); ++i)
        {
            if (marked[adj[x][i].second] == false)
            {
                Q.push(adj[x][i]);
            }
        }
    }
    return minimumCost;
}

int main()
{
    long n, m, x, y, w;
    cin >> n >> m;
    for (long long i = 0; i < m; ++i)
    {
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(w, y));
        adj[y].push_back(make_pair(w, x));
    }
    cout << mst(1) << endl;
}
