// Given a snake and ladder board, find the minimum number of dice 
// throws required to reach the destination or last cell from source
//  or 1st cell. The player has total control over outcome of dice 
//  throw and wants to find out minimum number 
// of throws required to reach last cell.
// Starting from square 1, land on square 100 with the exact
//  roll of the die. 


// input -
// 2
// 3
// 32 62
// 42 68
// 12 98
// 7
// 95 13
// 97 25
// 93 37
// 79 27
// 75 19
// 49 47
// 67 17
// 4
// 8 52
// 6 80
// 26 42
// 2 72
// 9
// 51 19
// 39 11
// 37 29
// 81 3
// 59 5
// 79 23
// 53 7
// 43 33
// 77 21 

// output -
// 3
// 5

#include <bits/stdc++.h>
using namespace std;

struct point
{
	int v;
	int dist;
};

int bfs(int moves[], int sz)
{
	bool visited[sz+1];
	for(int i=0; i<=sz; i++)
		visited[i] = false;
	
	visited[1] = true;
	point p = {1, 0};
	queue<point> q;
	q.push(p);
	int snakes = 0;
	int slides = 0;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		int v = p.v;

		if(v == sz)
			break;
		visited[v] = true;

		for(int i=v+1; i<=(v+6) && i<=sz; i++)
		{
			if(!visited[i])
			{
				point newp;
				newp.dist = p.dist + 1;

				if(moves[i] != -1)
				{
					newp.v = moves[i];
					if(i > moves[i])
						snakes++;
					else
						slides++;
				}
				else
					newp.v = i;
				q.push(newp);
			}
		}
	}
	return p.dist;
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int sz = 100;
		int moves[sz+1];
		for(int i=0; i<=sz; i++)
			moves[i] = -1;
		int a, b;
		for(int i=0; i<n; i++)
		{
			cin>>a>>b;
			moves[a] = b;
		}
		int m;cin>>m;
		for(int i=0; i<m; i++)
		{
			cin>>a>>b;
			moves[a] = b;
		}
		cout<<bfs(moves, sz)<<endl;
	}
}