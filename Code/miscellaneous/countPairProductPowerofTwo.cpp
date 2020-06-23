// Given an array of N elements. The task is to count unordered 
// pairs (i, j) in the array such that the product of a[i] and a[j] 
// can be expressed as a power of two.

// Input : arr[] = {2, 3, 4, 8, 10}
// Output : 3
// Explanation: The pair of array element will be 
// (2, 4), (2, 8), (4, 8) whose product are 
// 8, 16, 32 respectively which can be expressed 
// as power of 2, like 2^3, 2^4, 2^5.

// Input : arr[] = { 2, 5, 8, 16, 128 }
// Output : 6

// Time Complexity: O(N), where N is the number 
// of elements in the array.

// z = x*y so if z is a power of 2, then x and y have to be a power 
// of two.
// So now we have to count the number of elements in the array 
// which can be expressed as a power of two. If the count is k, 
// then answer will be kC2 = k*(k-1)/2,
//  as we need the count of unordered pairs.

#include <bits/stdc++.h>
using namespace std;

bool powerofTwo(int a)
{
    return a && (!(a & (a - 1)));
}

void Count_pairs(int arr[], int n)
{
    if(n == 0)
        return;
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        if(powerofTwo(arr[i]))
            count++;
    }

    int ans = (count * (count - 1)) / 2;
    cout<<ans;
}

int main()
{
    int a[] = { 2, 5, 8, 16, 128 }; 
  
    int n = sizeof(a) / sizeof(a[0]); 
  
    Count_pairs(a, n); 
  
    return 0; 
}