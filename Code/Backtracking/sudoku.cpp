// Input:
// 1
// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0

// Output:
// 3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 
// 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 
// 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9

#include <iostream>
using namespace std;
#define N 9

bool findUnassignedspot(int grid[N][N], int &row, int &col)
{
    for(row = 0; row <N;row++)
        for(col = 0; col <N;col++)
            if(grid[row][col] == 0)
                return true;
    return false;
}

bool usedInRow(int grid[N][N], int row, int num)
{
    for(int col = 0; col < N; col++)
        if(grid[row][col] == num)
            return true;
    return false;
}

bool usedInCol(int grid[N][N], int col, int num)
{
    for(int row = 0; row < N; row++)
        if(grid[row][col] == num)
            return true;
    return false;
}

bool usedInBox(int grid[N][N], int rowStart, int colStart, int num)
{
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
            if(grid[row+rowStart][col+colStart] == num)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return (!usedInRow(grid, row, num) &&
            !usedInCol(grid, col, num) &&
            !usedInBox(grid, row - row%3, col - col%3, num) &&
            grid[row][col] == 0);
}

bool solveSudoku(int grid[N][N])
{
    int row, col;
    
    if(!findUnassignedspot(grid, row, col))
        return true;
    
    for(int num = 1; num <=N;num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if(solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printSoln(int grid[N][N])
{
    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++)
            cout<<grid[row][col]<<" ";
    cout<<endl;
}

int main() {
	int t;cin>>t;
	while(t--)
	{
	    int grid[N][N];
	    for(int i = 0;i <N;i++)
	        for(int j = 0;j<N;j++)
	            cin>>grid[i][j];
	   
	    if(solveSudoku(grid) == true)
	        printSoln(grid);
	    else cout<<-1;
	}
	return 0;
}