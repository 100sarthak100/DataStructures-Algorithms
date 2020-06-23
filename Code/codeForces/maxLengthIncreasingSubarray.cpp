// You are given array consisting of n integers. Your task is to find the maximum
//  length of an increasing subarray of the given array.

// A subarray is the sequence of consecutive elements of the array. Subarray is 
// called increasing if each element of this 
// subarray strictly greater than previous.

// inputCopy
// 5
// 1 7 2 11 15
// outputCopy
// 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int cur = 1;
    int maxCur = INT_MIN;
    for(int i = 0; i<n-1; i++)
    {
        if(arr[i+1] > arr[i])
        {
            cur++;
            maxCur = max(maxCur, cur);
        }
        else
        {
            cur = 1;
        } 
    }
    maxCur = (maxCur == INT_MIN) ? 1 : maxCur;
    cout<<maxCur<<endl;
}