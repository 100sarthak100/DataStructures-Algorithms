// Given an array of integers (A[])  and a number x, find the 
// smallest subarray with sum greater than the given value.

// Note: The answer always exists. It is guaranteed that x doesn't 
// exceed the summation of a[i] (from 1 to N).

// Example 1:

// Input:
// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is 
// {4, 45, 6}


// Example 2:

// Input:
// A[] = {1, 10, 5, 2, 7}
//    x  = 9
// Output: 1
// Explanation:
// Minimum length subarray is {10}

// Time - O(N)
// Space - O(1)

int sb(int arr[], int n, int x)
{
    int minLen = n+1;
    int curSum = 0;
    int start = 0, end = 0;
    while(end < n)
    {
        while(curSum <= x && end < n)
        {
            curSum += arr[end];
            end++;
        }
        
        while(curSum > x && start < n)
        {
            if(end - start < minLen)
                minLen = end - start;
            
            curSum -= arr[start];
            start++;
        }
    }
    
    return minLen;
}