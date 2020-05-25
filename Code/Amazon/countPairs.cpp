#include <bits/stdc++.h>
using namespace std;

int getPairs(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
        m[arr[i]]++;
    int count = 0, j;
    for (int i = 0; i < n; ++i)
    {
        j = k - arr[i];
        count += m[j];
        if (j == arr[i])
            count--;
    }
    return count / 2;
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        cout << getPairs(arr, n, k) << endl;
    }
}