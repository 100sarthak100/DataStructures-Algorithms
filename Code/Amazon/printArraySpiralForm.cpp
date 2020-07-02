#include <bits/stdc++.h>
using namespace std;

void printSpiral(int arr[][4], int n, int m)
{
    int rowStart = 0, rowEnd = n;
    int colStart = 0, colEnd = m;
    while (rowStart < rowEnd && colStart < colEnd)
    {
        for (int i = colStart; i < colEnd; i++)
            cout << arr[rowStart][i] << " ";
        rowStart++;
        for (int i = rowStart; i < rowEnd; i++)
            cout << arr[i][colEnd - 1] << " ";
        colEnd--;
        if (colStart < colEnd)
        {
            for (int i = colEnd - 1; i >= colStart; i--)
                cout << arr[rowEnd - 1][i] << " ";
            rowEnd--;
        }

        if (rowStart < rowEnd)
        {
            for (int i = rowEnd - 1; i >= rowStart; i--)
                cout << arr[i][colStart] << " ";
            colStart++;
        }
    }
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}}
                     ;
    int n = 3, m = 4;
    printSpiral(arr, n, m);
}