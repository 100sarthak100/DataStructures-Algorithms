#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    deque<int> Q(k);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ((!Q.empty()) && arr[i] >= arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (; i < n; ++i)
    {
        cout << arr[Q.front()] << " ";
        while ((!Q.empty()) && Q.front() <= i - k)
            Q.pop_front();
        while ((!Q.empty()) && arr[i] >= arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    cout << arr[Q.front()];
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
}