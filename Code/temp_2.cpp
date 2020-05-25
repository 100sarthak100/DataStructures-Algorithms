#include <iostream>
using namespace std;
#define N 9

bool findUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for(row = 0; row < N; row++)
        for(col = 0; col < N; col++)
            if(grid[row][col] == 0)
                return true;
    return false;
}
bool usedInRow(int grid[][N], int row, int num)
{
    for(int col= 0; col<N;col++)
        if(grid[row][col] == num)
            return true;
    return false;
}

bool usedInCol(int grid[][N], int col, int num)
{
    for(int row = 0; row < N; row++)
        if(grid[row][col] == num)
            return true;
return false;
}

bool usedInBox(int grid[][N], int boxStartRow, int boxStartCol, int num)
{
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
            if(grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !usedInRow(grid, row, num)
        && !usedInCol(grid, col, num)
        && !usedInBox(grid, row - row%3, col - col%3, num)
        && grid[row][col] == 0;
}

bool solveSudoku(int grid[N][N])
{
    int row, col;
    if(!findUnassignedLocation(grid, row, col))
        return true;
    
    for(int num = 1; num <= 9; num++)
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

void printSoln(int grid[][N])
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