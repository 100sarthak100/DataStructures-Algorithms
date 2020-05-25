// (0)--(1)--(2)
//  |   / \   |
//  |  /   \  | 
//  | /     \ |
// (3)-------(4)

// (0)--(1)--(2)
//  |   / \   |
//  |  /   \  | 
//  | /     \ |
// (3)      (4)

// Solution Exists: Following is one Hamiltonian Cycle
//  0  1  2  4  3  0

// Solution does not exist

#include <bits/stdc++.h>
using namespace std;
#define V 5

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    if(graph[path[pos - 1]][v] == 0)
        return false;
    
    for(int i = 0;i<pos;i++)
        if(path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    if(pos == V)
    {
        if(graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for(int v = 1; v<V; v++)
    {
        if(isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if(hamCycleUtil(graph, path, pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void printSoln(int path[])
{
    for(int i = 0;i<V;i++)
        cout<<path[i]<<" ";
    
    cout<<path[0]<<" ";
    cout<<endl;
}

bool hamCycle(bool graph[V][V])
{
    int path[V];
    memset(path, -1, sizeof(path));

    path[0] = 0;
    if(hamCycleUtil(graph, path, 1) == false)
    {
        cout<<"no solution"<<endl;
        return false;
    }

    printSoln(path);
    return true;
}

int main()
{
    bool graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
      
    // Print the solution  
    hamCycle(graph1);

    bool graph2[V][V] = {{0, 1, 0, 1, 0},  
                         {1, 0, 1, 1, 1},  
                         {0, 1, 0, 0, 1},  
                         {1, 1, 0, 0, 0},  
                         {0, 1, 1, 0, 0}};  
  
    // Print the solution  
    hamCycle(graph2);  
  
    return 0;  
}