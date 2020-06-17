// We need to find the next lexicographic permutation of the 
// given list of 
// numbers than the number formed by the given array.

// start from the end find the first decreasing number , that our pivot
// , now from the end find the number just greater than the pivot.
// swap them, now reverse the list from pivot+1 to th end.
// if pivot == -1 reverse whole array


// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

// Time complexity : O(n)O(n). 
// In worst case, only two scans of the whole array are needed.

// Space complexity : O(1)O(1). No extra space is used. 
// In place replacements are done.

class Solution {
public:
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void reverse(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            swap(&nums[start], &nums[end]);
            start++;
            end--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int pivotIndex = nums.size() - 2;
        
        while(pivotIndex >= 0 && nums[pivotIndex] >= nums[pivotIndex + 1])
            pivotIndex--;
        
        if(pivotIndex == -1)
        {
            reverse(nums, 0, nums.size() - 1);
            return;
        }
        
        for(int i = nums.size()-1; i> pivotIndex; i--)
        {
            if(nums[i] > nums[pivotIndex])
            {
                swap(&nums[i], &nums[pivotIndex]);
                break;
            }
        }
        
        reverse(nums, pivotIndex+1, nums.size() - 1);
        
        return;
    }
};