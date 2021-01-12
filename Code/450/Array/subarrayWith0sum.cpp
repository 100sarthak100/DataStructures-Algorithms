// Given an array of positive and negative numbers. Find if there is a 
// subarray (of size at-least one) with 0 sum.

// Example 1:

// Input:
// 5
// 4 2 -3 1 6

// Output: 
// Yes

// Explanation: 
// 2, -3, 1 is the subarray 
// with sum 0.

// Example 2:

// Input:
// 5
// 4 2 0 1 6

// Output: 
// Yes

// Explanation: 
// 0 is one of the element 
// in the array so there exist a 
// subarray with sum 0.

// Time - O(N)
// Space - O(N)

bool subArrayExists(int arr[], int n)
{
    int i = 0;
    int currSum = 0;
    if(n == 0)
        return false;
        
    int arr1[n];
    arr1[0] = arr[0];

    for(int i=1; i<n; i++)
        arr1[i] = arr1[i-1] + arr[i];
        
    // for(int i=0; i<n; i++)
    //     cout<<arr1[i]<<" ";
      
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[arr1[i]]++;
        if(arr1[i] == 0)
            return true;
        if(mp[arr1[i]] > 1)
            return true;
    }
        
    return false;
    
    // 4 6 3 4 10
    // 10 6 4 7 6
}