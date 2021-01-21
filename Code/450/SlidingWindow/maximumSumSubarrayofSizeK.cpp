// Given an array of integers Arr of size N and a number K. Return 
// the maximum sum of a subarray of size K.

// Example 1:

// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output:
// 700
// Explanation:
// Arr3  + Arr4 =700,
// which is maximum.

// Example 2:

// Input:
// N = 4, K = 4
// Arr = [100, 200, 300, 400]
// Output:
// 1000
// Explanation:
// Arr1 + Arr2 + Arr3  
// + Arr4 =1000,
// which is maximum.

// Time - O(N)
// Space - O(1)

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i = 0, j = 0, currSum = 0, maxSum = INT_MIN;
        while(j < N)
        {
            currSum += Arr[j];
            if(j - i + 1 < K)
                j++;
            else if(j - i + 1 == K)
            {
                maxSum = max(maxSum, currSum);
                currSum -= Arr[i];
                i++;
                j++;
            }
        }
        
        return maxSum;
    }
};