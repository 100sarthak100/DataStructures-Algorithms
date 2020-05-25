#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = *a;
}

void printArray(int arr[][10], int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void transpose(int arr[][10], int r, int c)
{
    for (int i = 0; i < r; ++i)
        for (int j = i; j < c; j++)
            swap(arr[i][j], arr[j][i]);
}

void rotateMatrixAntiClock(int arr[][10], int r, int c)
{
    for (int i = 0; i < c; i++)
        for (int j = 0, k = c - 1; j < k; j++, k--)
            swap(arr[j][i], arr[k][i]);
}

void rotateMatrixClock(int arr[][10], int r, int c)
{
    //clockwise rotate (reverse row)
    for (int i = 0; i < r; i++)
        for (int j = 0, k = r - 1; j < k; j++, k--)
            swap(arr[i][j], arr[i][k]);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int arr[10][10];
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> arr[i][j];

        transpose(arr, r, c);
        rotateMatrixClock(arr, r, c);
        printArray(arr, r, c);
    }
}