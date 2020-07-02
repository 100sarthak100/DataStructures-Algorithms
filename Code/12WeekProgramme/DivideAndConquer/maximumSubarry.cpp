// Given an integer array nums, find the contiguous subarray 
// (containing at least one number) which has the largest sum 
// and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// using Kaden's algo
// time - O(N)
// space - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sofar = INT_MIN;
        int maxSum = 0;
        int s= 0, start = 0, end = 0;
        int n = nums.size();
        int i=0;
        while(i < n)
        {
             maxSum += nums[i];
            if(max_sofar < maxSum)
            {
                max_sofar = maxSum;
                start = s;
                end = i;
            }
            
            if(maxSum < 0)
            {
                maxSum = 0;
                s = i + 1;
            }
           
            i++;
        }
        cout<<start<<" "<<end<<endl;
        return max_sofar;
    }
};

// divide and conquer method
// just gives sum
// time - O(nlogn)
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxSubarryCrossing(int arr[], int l, int m, int h)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for(int i=m; i>=l; i--)
    {
        sum += arr[i];
        if(sum > leftSum)
            leftSum = sum;
    }
    
    int rightSum = INT_MIN;
    sum = 0;
    for(int i=m+1; i<=h; i++)
    {
        sum += arr[i];
        if(sum > rightSum)
            rightSum = sum;
    }
    
    return max(leftSum + rightSum, leftSum, rightSum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if(l == h)
        return arr[l];
    
    int m = (l + h)/2;
    return max(maxSubArraySum(arr, l, m), 
            maxSubArraySum(arr, m+1, h), maxSubarryCrossing(arr, l, m, h));
}


int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<maxSubArraySum(arr, 0, n-1)<<endl; 
	}
	return 0;
}
