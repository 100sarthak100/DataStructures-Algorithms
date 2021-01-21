// Time - O(n^2)
// SPace - O(1)

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void transpose(int matrix[][3], int n, int m)
{
    for(int i=0; i<n; i++)
        for(int j=i; j<m; j++)
            swap(matrix[i][j], matrix[j][i]);
}

void printMatrix(int matrix[][3], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;       
    }
}

// transpose
// 1, 4, 7
// 2, 5, 8
// 3, 6, 9

// interchange collumns
void rotateClockwise(int matrix[][3], int n, int m)
{
    transpose(matrix, n, m);
    for(int i=0; i<n; i++)
    {
        for(int j=0, k=m-1; j<k; j++,k--)
            swap(matrix[i][j], matrix[i][k]);
    }

    printMatrix(matrix, n, m);
}

// interchange rows
void rotateAntiClockwise(int matrix[][3], int n, int m)
{
    transpose(matrix, n, m);
    for(int i=0; i<m; i++)
    {
        for(int j=0, k=n-1; j<k; j++,k--)
            swap(matrix[j][i], matrix[k][i]);
    }

    printMatrix(matrix, n, m);
}

int main()
{
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    
    rotateClockwise(matrix, 3, 3);
    // clockwise 90
    // 7 4 1
    // 8 5 2
    // 9 6 3
    cout<<endl;
    rotateAntiClockwise(matrix, 3, 3);
    // anticlockwise 90
    // 3 6 9
    // 2 5 8
    // 1 4 7
}