// Given an array of integers (A[])  and a number x, 
// find the smallest subarray with sum greater than the given 
// value.

// Input:
// 2
// 6 51
// 1 4 45 6 0 19
// 5 9
// 1 10 5 2 7
// Output:
// 3
// 1

Examples:
A[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

#include<bits/stdc++.h>
using namespace std;

int minArr(int arr[], int n, int x)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int minLen = INT_MAX;
    while(j < n)
    {
        if(sum + arr[j] < x)
        {
            sum += arr[j];
            j++;
        }
        else
        {
            sum += arr[j];
            while(sum > x && i < n)
            {
                sum -= arr[i];
                if(sum > x)
                    i++;
                else
                {
                    sum += arr[i];
                    break;
                }
            }
            minLen = min(minLen, j - i + 1);
            j++;
        }
    }
    return minLen;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, x;cin>>n>>x;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<minArr(arr, n, x)<<endl;
	}
	return 0;
}