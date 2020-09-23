// Given an array A of positive integers. Your task is to find the 
// leaders in the array.

// Note: An element of array is leader if it is greater than or equal 
// to all the elements to its right side. Also, the rightmost element 
// is always a leader. 

// Example 1:

// Input:
// N = 6
// A[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: The first leader is 17 
// as it is greater than all the elements 
// to its right.  Similarly, the next 
// leader is 5. The right most element 
// is always a leader so it is also 
// included.
// Example 2:

// Input:
// N = 5
// A[] = {1,2,3,4,0}
// Output: 4 0
// Explanation: 4 and 0 are leaders.

// Time - O(N)
// Space - O(1)

vector<int> leaders(int arr[], int n){
    
    int maxVal = -1;
    vector<int> ret;
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] >= maxVal)
        {
            maxVal = arr[i];
            ret.push_back(arr[i]);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}