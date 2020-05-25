#include <bits/stdc++.h>
using namespace std;

void fillOrder(int v, bool visited[], stack<int> &st)
{
    visited[v] = true;
    for(int i = 0;i < adj[v].size(); i++)
        if(!visited[adj[v][i]])
            fillOrder(adj[v][i], visited, st);

    st.push(v);
}

void getTranspose()
{
    for(int v = 0; v < V; v++)
    {
        for(int i = 0; i < adj[v].size(); i++)
            adj[i].push_back(v);
    }
}

int printSCG()
{
    stack<int> st;
    bool*visited = new bool[V];
    for(int i = 0;i<V;i++)
        visited[i] = false;

    for(int i = 0;i<V;i++)
        if(visited[i] == false)
            fillOrder(i, visited, st);

    getTranspose();
}

int main()
{

}