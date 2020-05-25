// Input:
// 2
// 6
// 11 26 3 22 5 8 20 29 27 1 21 9
// 1
// 2 30

// Output:
// 3
// 1
// find shortest path using Breadth First Search of the graph.


#include <bits/stdc++.h>
using namespace std;

struct queueEntry
{
    int v;
    int dist;
};


int minDiceThrow(int moves[], int n)
{
    bool* visited = new bool[n];
    for(int i = 0;i<n;i++)
        visited[i] = false;
    
    queue<queueEntry> q;  
    visited[0] = true;
    q.push({0, 0});
    queueEntry qe;
    
    while(!q.empty())
    {
        qe = q.front();
        int v = qe.v;
        
        if(v == n-1)
            break;
        
        q.pop();
        for(int i = v+1; i<=(v+6) && i<n;i++)
        {
            if(!visited[i])
            {
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[i] = true;
                
                if(moves[i] != -1)
                    a.v = moves[i];
                else
                    a.v = i;
                    
                q.push(a);
            }
        }
    }
    return qe.dist;
}


int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n,a,b;cin>>n;
	    int N = 30;
	    int moves[N];
	    memset(moves, -1, sizeof(moves));
	    for(int i = 0;i<n;i++)
	    {
	        cin>>a>>b;
	        moves[a-1] = b-1;
	    }
	    cout<<minDiceThrow(moves, N)<<endl;
	}
	return 0;
}