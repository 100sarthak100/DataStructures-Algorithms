// Input
// 2
// 1
// 4
// Output:
// [1 ]
// [2 4 1 3 ] [3 1 4 2 ]

#include <bits/stdc++.h>
using namespace std;
#define MAX 10

bool isSafe(int board[][MAX], int row, int col, int n)
{
    // row on left side
    for(int i = 0; i<col;i++)
        if(board[row][i])
            return false;
    
    // upper diagonal left side
    for(int i=row,j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return false;
            
    // lower diagonal left side
    for(int i=row,j=col; i<n &&j>=0; i++,j--)
        if(board[i][j])
            return false;
            
    return true;
        
}

void printSoln(int board[][MAX], int n, vector<vector<int>> &ret, vector<int> &vec)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            if(board[i][j] == 1)
                vec.push_back(j+1);
    }
    ret.push_back(vec);
    vec.clear();
}

void solveQueen(int board[][MAX], int col, int n, vector<vector<int>> &ret, vector<int> &vec)
{
    if(col == n)
    {
        printSoln(board, n, ret, vec);
        return;
    }
    
    for(int i = 0;i<n;i++)
    {
        if(isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            solveQueen(board, col+1, n, ret, vec);
            board[i][col] = 0;
        }
    }
    return;
}


int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int board[MAX][MAX];
	    memset(board, 0, sizeof(board));
	    vector<vector<int>> ret;
	    vector<int> vec;
	    solveQueen(board, 0, n, ret, vec);
	    if(ret.empty())
	        cout<<-1;
	    else
	    {
	        sort(ret.begin(), ret.end());
	        for(auto i : ret)
	        {
	            cout<<"[";
	            for(auto x : i)
	                cout<<x<<" ";
	            cout<<"]"<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}