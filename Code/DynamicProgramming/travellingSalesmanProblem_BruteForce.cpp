// Travelling Salesman Problem (TSP): Given a set of cities and 
// distance between every pair of cities, the problem is to find 
// the shortest possible route that visits every city exactly once 
// and returns back to the starting point.

// Time Complexity: Θ(n!)

#include <bits/stdc++.h>
using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> ret;
    for(int i=0; i<V; i++)
    {
        if(i != s)
            ret.push_back(i);
    }

    int minVal = INT_MAX;
    do
    {
        int val = 0;
        int start = s;
        int end;
        for(int i=0; i<ret.size(); i++)
        {
            end = ret[i];
            val += graph[start][end];
            start = end;
        }
        val += graph[end][s];
        minVal = min(minVal, val);

    } while (next_permutation(ret.begin(), ret.end()));

    return minVal;
}

int main()
{
    int graph[][V] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; 
    int s = 0; 
    cout << travllingSalesmanProblem(graph, s) << endl; 
    return 0;
}