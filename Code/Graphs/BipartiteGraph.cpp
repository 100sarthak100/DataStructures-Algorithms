// A Bipartite Graph is a graph whose vertices can be divided into 
// two independent sets, U and V such that every edge (u, v) either 
// connects a vertex from U to V or a vertex from V to U. 

// We can also say that there is no edge that connects vertices of 
// same set.

// Two coloring problem

// Input:
// 2
// 4
// 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 0
// 3
// 0 1 0 0 0 1 1 0 0
// Output:
// 1
// 0

// time - O(V+E)
//dfs (also handles disconnected components)
bool dfs(int G[][MAX], int V, int color[], int pos, int c)
{
    if(color[pos] != -1 && color[pos] != c)
        return false;
    
    color[pos] = c;
    for(int i=0; i<V; i++)
    {
        if(G[pos][i])
        {
            if(color[i] == -1)
            {
                if(dfs(G, V, color, i, 1-c) == false)
                    return false;
            }
            if(color[i] != -1 && color[i] != 1-c)
                return false;
        }
    }
    return true;
}


bool isBipartite(int G[][MAX],int V)
{
    int color[V]; 
    for(int i=0;i<V;i++) 
        color[i] = -1;
    
    int pos = 0;
    
    for(int i=0; i<V; i++)
    {
        if(color[i] == -1)
        {
            if(dfs(G, V, color, i, 1) == false)
                return false;
        }
    }
    return true;
}