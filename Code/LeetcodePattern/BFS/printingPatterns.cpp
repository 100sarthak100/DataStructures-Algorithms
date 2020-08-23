// You are required to form a matrix of size  where  is the number 
// of rows and  is the number of columns. You are required to form 
// the waves of numbers around the provided center,  (0-based 
// indexing).

// Example:

// Size of the matrix:  and 
// Center coordinates:  and  (0 based indexing)
// Pattern:
//             4 4 4 4 4 4 4 4 4 
//             4 3 3 3 3 3 3 3 4 
//             4 3 2 2 2 2 2 3 4 
//             4 3 2 1 1 1 2 3 4 
//             4 3 2 1 0 1 2 3 4 
//             4 3 2 1 1 1 2 3 4 
//             4 3 2 2 2 2 2 3 4 
//             4 3 3 3 3 3 3 3 4 
//             4 4 4 4 4 4 4 4 4

// input -
// 10 10 5 5

// output -
// 5 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 4 4 
// 5 4 3 3 3 3 3 3 3 4 
// 5 4 3 2 2 2 2 2 3 4 
// 5 4 3 2 1 1 1 2 3 4 
// 5 4 3 2 1 0 1 2 3 4 
// 5 4 3 2 1 1 1 2 3 4 
// 5 4 3 2 2 2 2 2 3 4 
// 5 4 3 3 3 3 3 3 3 4 
// 5 4 4 4 4 4 4 4 4 4 

#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, int i, int j)
{
	return (i>=0 && i<r && j>=0 && j<c);
}

void bfs(int r, int c, int ci, int cj)
{
	vector<vector<int>> matrix(r+1, vector<int> (c+1, 0));
	vector<vector<int>> visited(r+1, vector<int> (c+1, false));
	queue<pair<int, int>> q;
	q.push({ci, cj});

	int dx[] = {1,1,-1,1,0,0,-1,-1};
	int dy[] = {1,-1,1,0,1,-1,0,-1};

	visited[ci][cj] = true;

	while(!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		
		for(int p=0; p<8; p++)
		{
			int newx = dx[p] + x;
			int newy = dy[p] + y;
			if(isValid(r, c, newx, newy) && !visited[newx][newy])
			{
				matrix[newx][newy] = 1 + matrix[x][y];
				visited[newx][newy] = true;
				q.push({newx, newy});
			}
		}
	}
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return;
}

int main()
{
	int r, c, ci, cj;
	cin>>r>>c>>ci>>cj;
	bfs(r, c, ci, cj);
	return 0;
}