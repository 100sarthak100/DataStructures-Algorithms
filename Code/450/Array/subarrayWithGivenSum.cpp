// Given an unsorted array A of size N that contains only non-
// negative integers, find a continuous sub-array which adds to a 
// given number S.

// Example 1:

// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4
// Explanation: The sum of elements 
// from 2nd position to 4th position 
// is 12.

// Example 2:

// Input:
// N = 10, S = 15
// A[] = {1,2,3,4,5,6,7,8,9,10}
// Output: 1 5
// Explanation: The sum of elements 
// from 1st position to 5th position
// is 15.

// Time - O(n);
// Space - O(1);

vector<int> subarraySum(int arr[], int n, int x){
    
    vector<int> ret;
    if(n == 0)
        return ret;
    int start = 0, end = 0;
    int curSum = 0;
    while(end < n)
    {
        while(curSum < x && end < n)
        {
            curSum += arr[end];
            end++;
        }
        // cout<<start<<" "<<end<<endl;
        while(curSum > x && start < n)
        {
            curSum -= arr[start];
            start++;
            if(curSum == x)
                break;
        }
        // cout<<start<<" "<<end<<endl;
        if(curSum == x)
        {
            ret.push_back(start+1);
            ret.push_back(end);
            return ret;
        }
    }
    ret.push_back(-1);
    return ret;
    
}