// Given a matrix of N*M order. Find the shortest distance 
// from a source cell to a destination cell, traversing through 
// limited cells only. Also you can move only up, down, left and 
// right. If found output the distance else -1.
// s represents ‘source’
// d represents ‘destination’
// * represents cell you can travel
// 0 represents cell you can not travel
// This problem is meant for single source and destination.

Examples:

Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1

#include <bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

struct point
{
    int x;
    int y;
    int w;
};

bool isValid(int x, int y)
{
    return (x>=0 && y>=0 && x<N && y<M);
}

int bfs(char grid[][M], int i, int j)
{
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    vector<vector<bool>> visited(N+1, vector<bool> (M+1, false));
    queue<point> q;
    point p = {i, j, 0};
    q.push(p);
    int count = 0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        int x = p.x;
        int y = p.y;
        if(grid[x][y] == 'd')
            return p.w;

        if(visited[x][y])
            continue;

        visited[x][y] = true;

        for(int pp=0; pp<4; pp++)
        {
            int newx = dx[pp] + x;
            int newy = dy[pp] + y;
            if(isValid(newx, newy) && !visited[newx][newy] && grid[newx][newy] != '0')
                q.push({newx, newy, p.w+1});
        }
    }
    return -1;
}

int minDistance(char grid[][M])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(grid[i][j] == 's')
            {
                int a = bfs(grid, i, j);
                return a;
            }
        }
    }
    return -1;
}

int main()
{
    char grid[N][M] = { { '0', '*', 's', '0' }, 
                        { '*', '0', '*', '*' }, 
                        { '0', '*', '0', '*' }, 
                        { 'd', '*', '*', '*' } }; 
  
    cout << minDistance(grid); 
    return 0; 
}