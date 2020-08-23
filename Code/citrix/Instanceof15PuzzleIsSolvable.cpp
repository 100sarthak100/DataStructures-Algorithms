// Given a 4×4 board with 15 tiles (every tile has one number 
// from 1 to 15) and one empty space. The objective is to place 
// the numbers on tiles in order using the empty space. We can 
// slide four adjacent (left, right, above and below) 
// tiles into the empty space. 

For a 4x4 15 tiles puzzle
// In general, for a given grid of width N, we can find 
// out check if a N*N – 1 puzzle is solvable or not by 
// following below simple rules :

// If N is odd, then puzzle instance is solvable if number 
// of inversions is even in the input state.
// If N is even, puzzle instance is solvable if
// the blank is on an even row counting from the bottom 
// (second-last, fourth-last, etc.) and number of inversions 
// is odd.
// the blank is on an odd row counting from the bottom 
// (last, third-last, fifth-last, etc.) and number of 
// inversions is even.
// For all other cases, the puzzle instance is not solvable.

For a 3x3 8 puzzle
// Following is simple rule to check if a 8 puzzle is solvable.
// It is not possible to solve an instance of 8 puzzle if 
// number of inversions is odd in the input state.

#include <bits/stdc++.h>
using namespace std;
#define N 4

int getInvCount(int arr[])
{
    int count = 0;
    for(int i=0; i<N*N-1; i++)
    {
        for(int j=i+1; j<N*N; j++)
        {
            if(arr[i] && arr[j] && arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int posOfZero(int arr[][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i][j] == 0)
                return N - i;
        }
    }
    return -1;
}

bool isSolvable(int puzzle[][N])
{
    int invCount = getInvCount((int*)puzzle);

    // if N is odd and inverCount is even -> is solvable
    if(N%2 != 0)
    {
        if(invCount%2 == 0)
            return true;
        else
            return false;
    }
    else
    {
        int pos = posOfZero(puzzle);
        if(pos == -1)
            return false;
        else
        {   // if N is even , pos is even and invCount 
            // is odd -> is solavable
            if(pos%2 == 0)
            {
                if(invCount%2 != 0)
                    return true;
                else
                    return false;
            }
            else // if N is even, pos(odd), invCount(even) -> is solvable
            {
                if(invCount%2 == 0)
                    return true;
                else
                    return false;
            }  
        }
    }
    return false;
}

int main()
{
    int puzzle[N][N] = 
    { 
        {12, 1, 10, 2}, 
        {7, 11, 4, 14}, 
        {5, 0, 9, 15}, // Value 0 is used for empty space 
        {8, 13, 6, 3}, 
    }; 
    isSolvable(puzzle)? cout << "Solvable": 
                        cout << "Not Solvable"; 
    return 0; 
}