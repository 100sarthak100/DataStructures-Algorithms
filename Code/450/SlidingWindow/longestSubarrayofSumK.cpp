// Given an array arr[] of size N containing integers. The task is to 
// find the length of the longest sub-array having sum equal to the 
// given value K.

// Time - O(N)
// Space - O(1)

// Only works for positive number array

#include <bits/stdc++.h>
using namespace std;

int subarrayLength(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int maxLength = INT_MIN, sum = 0;

    while(j < n)
    {
        sum += arr[j];
        if(sum < k)
            j++;
        else if(sum == k)
        {
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        else if(sum > k)
        {
            while(sum > k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return maxLength;
}

int main()
{
    int arr[] = {4, 1, 1, 1, 2, 2, 3, 5};
    int n = 7;
    int k = 5;
    cout<<subarrayLength(arr, n, k)<<endl;
}