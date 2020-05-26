// Input : mat[][] = {{1, 3, 3},
//                    {2, 1, 4},
//                   {0, 6, 4}};
// Output : 12 
// {(1,0)->(2,1)->(2,2)}

// Input: mat[][] = { {1, 3, 1, 5},
//                    {2, 2, 4, 1},
//                    {5, 0, 2, 3},
//                    {0, 6, 1, 2}};
// Output : 16
// (2,0) -> (1,1) -> (1,2) -> (0,3) OR
// (2,0) -> (3,1) -> (2,2) -> (2,3)

// Input : mat[][] = {{10, 33, 13, 15},
//                   {22, 21, 04, 1},
//                   {5, 0, 2, 3},
//                   {0, 6, 14, 2}};
// Output : 83

// Time Complexity :O(m*n)
// Space Complexity :O(m*n)

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int getMaxGold(int gold[][MAX], int m, int n)
{
    int goldTable[m][n];
    memset(goldTable, 0, sizeof(goldTable));

    for(int col = n-1; col >=0; col--)
    {
        for(int row=0; row<m; row++)
        {
            int right = (col==n-1)? 0: goldTable[row][col+1];

            int right_up = (row==0 || col==n-1)? 0:
                            goldTable[row-1][col+1];
                
            int right_down = (row==m-1 || col==n-1)? 0:
                            goldTable[row+1][col+1];
            
            goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down));
        }
    }
    // for(int i = 0;i<m;i++)
    // {
    //     for(int j = 0;j<n;j++)
    //         cout<<goldTable[i][j]<<" ";
    //     cout<<endl;
    // }
    int maxEle = INT_MIN;
    for(int i = 0;i<m;i++)
        maxEle = max(maxEle,  goldTable[i][0]);
    return maxEle;
}

int main() 
{ 
    int gold[MAX][MAX]= { {1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2} 
    }; 
    int m = 4, n = 4; 
    cout << getMaxGold(gold, m, n); 
    return 0; 
} 