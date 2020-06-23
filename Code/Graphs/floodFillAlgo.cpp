// Given a 2D screen, location of a pixel in the screen and a 
// color, replace color of the given pixel and 
// all adjacent same colored pixels with the given color.

// Input:
//        screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
//                       {1, 1, 1, 1, 1, 1, 0, 0},
//                       {1, 0, 0, 1, 1, 0, 1, 1},
//                       {1, 2, 2, 2, 2, 0, 1, 0},
//                       {1, 1, 1, 2, 2, 0, 1, 0},
//                       {1, 1, 1, 2, 2, 2, 2, 0},
//                       {1, 1, 1, 1, 1, 2, 1, 1},
//                       {1, 1, 1, 1, 1, 2, 2, 1},
//                       };
//     x = 4, y = 4, newColor = 3

// output
// Updated screen after call to floodFill:
// 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 0 0
// 1 0 0 1 1 0 1 1
// 1 3 3 3 3 0 1 0
// 1 1 1 3 3 0 1 0
// 1 1 1 3 3 3 3 0
// 1 1 1 1 1 3 1 1
// 1 1 1 1 1 3 3 1


#include <bits/stdc++.h>
using namespace std;

#define M 8 
#define N 8

void floodFillUtil(int screen[][N], int x, int y, int newC, int prevC)
{
    if(x<0 || x>=M || y<0 || y>=N)
        return;
    if(screen[x][y] != prevC)
        return;
    if(screen[x][y] == newC)
        return;

    screen[x][y] = newC;

    floodFillUtil(screen, x+1, y, newC, prevC);
    floodFillUtil(screen, x-1, y, newC, prevC);
    floodFillUtil(screen, x, y+1, newC, prevC);
    floodFillUtil(screen, x, y-1, newC, prevC);
}

void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, newC, prevC);
    return;
}

int main() 
{ 
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newC = 3; 
    floodFill(screen, x, y, newC); 
  
    cout << "Updated screen after call to floodFill: n"; 
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << screen[i][j] << " "; 
        cout << endl; 
    } 
} 