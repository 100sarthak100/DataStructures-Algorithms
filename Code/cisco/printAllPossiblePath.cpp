// The problem is to print all the possible paths from top left 
// to bottom right of an mXn matrix with the constraints that from 
// each cell you can 
// either move up, right, left or down.

// Input :  
// 1 2 3 
// 4 5 6 
// Output :  
// 1 2 3 6 
// 1 2 5 6  
// 1 4 5 6  
// 4 5 2 3 6 

// Input :
// 1 2 3
// 4 5 6
// 7 8 9
// Output :
// 1 2 3 6 9 
// 1 2 3 6 5 8 9 
// 1 2 3 6 5 4 7 8 9 
// 1 2 5 6 9 
// 1 2 5 8 9 
// 1 2 5 4 7 8 9 
// 1 4 5 6 9 
// 1 4 5 8 9 
// 1 4 5 2 3 6 9 
// 1 4 7 8 9 

#include <bits/stdc++.h>
using namespace std;

void printAllPath(vector<vector<int>> vec, vector<vector<int>> visited, int i, int j, vector<int> res)
{
    if(i<0 || j<0 || i>vec.size()-1 || j>vec[0].size()-1 || visited[i][j] == 1)
        return;
    
    if(i == vec.size()-1 && j == vec[0].size() - 1)
    {
        res.push_back(vec[i][j]);
        
        for(int k=0; k<res.size(); k++)
            cout<<res[k]<<" ";
        cout<<endl;
        return;
    }
    
    visited[i][j] = 1;
    res.push_back(vec[i][j]);
    
    printAllPath(vec, visited, i, j+1, res);
    
    printAllPath(vec, visited, i+1, j, res); 
    
    printAllPath(vec, visited, i, j-1, res); 
    
    printAllPath(vec, visited, i-1, j, res); 
    
    res.pop_back();
    visited[i][j] = 0;
}

int main() 
{ 
    // Given matrix 
    vector<vector<int> > vec = { { 1, 2, 3 }, 
                                 { 4, 5, 6 } }; 
  
    // mxn(2x3) 2d hash matrix 
    vector<vector<int> > visited(2, vector<int>(3, 0)); 
  
    // print All Path of matrix 
    vector<int> res;
    printAllPath(vec, visited, 0, 0, res); 
  
    return 0; 
} 