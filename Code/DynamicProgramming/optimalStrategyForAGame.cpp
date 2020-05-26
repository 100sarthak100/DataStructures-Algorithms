// You need to determine the maximum possible amouint of money you
//  can win if you go first.
// time - O(n^2)
// space - O(n^2)

// method - 1
// F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//               Vj + min(F(i+1, j-1), F(i, j-2) ))

// Base Cases
//     F(i, j) = Vi           If j == i
//     F(i, j) = max(Vi, Vj)  If j == i + 1

// method - 2
// F(i, j)  represents the maximum value the user can collect from 
//          i'th coin to j'th coin.
// arr[]   represents the list of coins

//     F(i, j)  = Max(Sum + F(i+1, j, Sum-arr[i]), 
//                    Sum + F(i, j-1, Sum-arr[j])) 
// Base Case
//     F(i, j)  = max(arr[i], arr[j])  If j == i+1

// Input:
// 2
// 4
// 5 3 7 10
// 4
// 8 15 3 7
// Output:
// 15
// 22

// Explanation:
// Testcase1: The user collects maximum value as 15(10 + 5)
// Testcase2: The user collects maximum value as 22(7 + 15)

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int memo[MAX][MAX];

int osrec(int arr[], int i, int j, int sum)
{
    if(j == i + 1)
        return max(arr[i], arr[j]);
    
    if(memo[i][j] != -1)
        return memo[i][j];
    
    memo[i][j] = max((sum - osrec(arr, i+1, j, sum - arr[i])),
                        (sum - osrec(arr, i, j-1, sum - arr[j])));

    return memo[i][j];
}

int optimalStrategyOfGame(int arr[], int n)
{
    int sum = 0;
    sum = accumulate(arr, arr+n, sum);
    memset(memo, -1, sizeof(memo));
    return osrec(arr, 0, n-1, sum);
}

int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2, n));

    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3, n));

    return 0;
}