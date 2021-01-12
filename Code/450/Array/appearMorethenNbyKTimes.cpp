// Given an array of size n, find all elements in array that appear 
// more than n/k times. For example, if the input arrays is 
// {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be 
// [2, 3]. Note that size of array is 8 (or n = 8), so we need to 
// find all elements that appear more than 2 (or 8/4) times. 
// There are two elements that appear more than two times, 2 and 3. 

// Time - O(N)
// Space > O(K)

#include <bits/stdc++.h>
using namespace std;

void appear(int arr[], int n, int k)
{
    int p = n/k;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
        mp[arr[i]]++;

    for(auto i : mp)
    {
        if(i.second > p)
            cout<<i.first<<" ";
    }

    return;
}

int main()
{
    int arr[] = {3,1,2,3,3,2,1,2};
    int k = 4;
    int n = 8;
    appear(arr, n, k);
}