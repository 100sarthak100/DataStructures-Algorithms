// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some 
// elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in 
// this array.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]

// time - O(N)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        vector<int> ret;
        int n = arr.size();
        if(n == 0)
            return ret;
        
        for(int i=0; i<n; i++)
        {
            if(arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > 0)
                ret.push_back(i + 1);
        }
        
        return ret;
    }
};