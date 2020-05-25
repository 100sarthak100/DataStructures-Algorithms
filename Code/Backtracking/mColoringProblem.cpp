//       (3)---(2) 
//        |   / | 
//        |  /  | 
//        | /   | 
//       (0)---(1) 
//  bool graph[V][V] = { 
//         { 0, 1, 1, 1 }, 
//         { 1, 0, 1, 0 }, 
//         { 1, 1, 0, 1 }, 
//         { 1, 0, 1, 0 }, 
//     };    
// matrix representation of the graph
// Solution Exists: Following are the assigned colors 
//  1  2  3  2
// time complexity = O(m^V)
// space complexity = O(V)
// check if the adjacent vertices have the same color or not.
// vertex coloring


#include <bits/stdc++.h>
using namespace std;
#define V 4

bool isSafe(int c, bool graph[][V], int color[], int v)
{
    for(int i = 0; i<V; i++)
    {
        if(graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[][V], int m, int color[], int v)
{
    if(v == V)
        return true;
    
    for(int c=1; c<=m; c++)
    {
        if(isSafe(c, graph, color, v))
        {
            color[v] = c;
            if(graphColoringUtil(graph, m, color, v+1) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void printSoln(int color[])
{
    for(int i = 0;i<V;i++)
        cout<<color[i]<<" ";
    cout<<endl;
}

bool graphColoring(bool graph[][V], int m)
{
    int color[V];
    memset(color, 0, sizeof(color));
    if(graphColoringUtil(graph, m, color, 0) == false)
    {
        cout<<"no solution"<<endl;
        return false;
    }

    printSoln(color);
    return true;
}

int main()
{
    bool graph[V][V] = { 
        { 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 }, 
        { 1, 1, 0, 1 }, 
        { 1, 0, 1, 0 }, 
    };
    int m = 3;
    graphColoring(graph, m);
}