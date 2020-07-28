// Consider a directed graph whose vertices are numbered from 1 to n. 
// There is an edge from a vertex i to a vertex j iff either j = i + 1
// or j = 3i. The task is to find the minimum number of edges in a 
// path in G from vertex 1 to vertex n.

// Input:
// 2
// 9
// 4

// Output:
// 2
// 2

#include<iostream>
using namespace std;

int minEdge(int n)
{
    if(n <= 1)
        return 0;
    if(n == 2)
        return 1;
    
    if(n%3 != 0)
    {
        return 1 + minEdge(n-1);
    }
    else
    {
        return 1 + minEdge(n/3);
    }
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<minEdge(n)<<endl;
	}
	return 0;
}