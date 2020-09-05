//  minimum number of steps for the knight to move to the said 
// point.
// Given any source point, (C, D) and destination point, (E, F) 
// on a chess board,

int X[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int Y[] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool isValid(int i, int j, int x, int y, set<pair<int, int>> &visited)
{
    return (i >= 1 && j >= 1 && i <= x && j <= y &&
            visited.find(make_pair(i, j)) == visited.end());
}

int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({C, D});
    int level[A + 1][B + 1];
    memset(level, 0, sizeof(level));

    // int **level = new int*[A+1];
    // for(int i = 0;i<=A;i++)
    //     level[i] = new int[B+1];
    // for(int i=0;i<=A;i++)
    // {
    //     for(int j=0;j<=B;j++)
    //     {
    //         level[i][j] = 0;
    //     }
    // }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == E && y == F)
            return level[x][y];
        for (int p = 0; p < 8; p++)
        {
            int newX = x + X[p];
            int newY = y + Y[p];
            if (isValid(newX, newY, A, B, visited))
            {
                level[newX][newY] = level[x][y] + 1;
                visited.insert({newX, newY});
                q.push({newX, newY});
            }
        }
    }
    return -1;
}

// best soln
// Input:
// 2
// 6
// 4 5
// 1 1
// 20
// 5 7
// 15 20

// Output:
// 3
// 9

#include<bits/stdc++.h>
using namespace std;

int arr[21][21];

bool isValid(int x, int y, int n)
{
    return (x>=0 && x<=n && y>=0 && y<=n);
}

int levelKnight(int n, int c, int d, int e, int f)
{
    int level[n+1][n+1];
    memset(level, 0, sizeof(level));
    bool visited[n+1][n+1];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({c, d});
    visited[c][d] = true;
    
    int dx[] = {-2,-2,-1,1,2,2, 1, -1};
    int dy[] = {-1, 1, 2,2,1,-1, -2, -2};
    
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        if(p.first == e && p.second == f)
            return level[e][f];
            
        for(int pp=0; pp<8; pp++)
        {
            int newx = dx[pp] + p.first;
            int newy = dy[pp] + p.second;
            if(isValid(newx, newy, n) && !visited[newx][newy])
            {
                level[newx][newy] = 1 + level[p.first][p.second];
                q.push({newx, newy});
                visited[newx][newy] = true;
            }
        }
    }
    return -1;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int c, d;
	    cin>>c>>d;
	    int e, f;
	    cin>>e>>f;
	    cout<<levelKnight(n, c, d, e, f)<<endl;
	}
	return 0;
}