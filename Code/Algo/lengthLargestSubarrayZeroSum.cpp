#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n)
{
    int maxLength = 0, sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];

        if (arr[i] == 0 && maxLength == 0)
            maxLength = 1;
        if (sum == 0)
            maxLength = i + 1;

        if (m.find(sum) != m.end())
        {
            maxLength = max(maxLength, i - m[sum]);
        }
        else
        {
            m.insert(make_pair(sum, i));
        }
    }

    return maxLength;
}

int main()
{
    int arr[] = {0, 15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest 0 sum subarray is "
         << maxLen(arr, n);
    return 0;
}