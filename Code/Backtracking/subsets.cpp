// Find all distinct subsets of a given set
// Input:  S = {1, 2, 2}
// Output:  {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}

#include <bits/stdc++.h>
using namespace std;

int printPowerSet(int arr[], int n)
{
    vector<string> list;
    for (int i = 0; i < (int)pow(2, n); i++)
    {
        string subset = "";
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                subset += to_string(arr[j]) + "|";
        }
    }
}

int main()
{
    int arr[] = {10, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printPowerSet(arr, n);
}