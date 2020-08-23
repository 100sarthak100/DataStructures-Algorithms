// Suppose an array sorted in ascending order is rotated at 
// some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array 
// return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of 
// O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// time - O(log n)

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] <= arr[h])
            {
                if(arr[mid] <= target && target <= arr[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            else
            {
                if(arr[mid] >= target && target >= arr[l])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};