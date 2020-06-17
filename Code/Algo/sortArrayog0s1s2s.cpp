// The problem is similar to our old post Segregate 0s and 1s in an array, 
// and both of these problems are variation of famous Dutch national flag problem.
Important Question!

// Method 1 : Dutch National Flag Algorithm OR 3-way Partitioning:
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Time Complexity: O(n).
// Only one traversal of the array is needed.
// Space Complexity: O(1).
// No extra space is required.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0 :
                    // same as
                    // swap(nums[low], nums[mid]);
                    // low++, mid++;
                    swap(nums[low++], nums[mid++]);
                    break;
                
                case 1 :
                    mid++;
                    break;
                
                case 2 :
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
        return;
    }
};

// Method 2 : Count 0, 1, 2 in array the replace the array with that particular 
// count

// Time Complexity: O(n).
// Only two traversals of the array is needed.
// Space Complexity: O(1).
// As no extra space is required.

#include <bits/stdc++.h> 
using namespace std; 
  
// Utility function to print the contents of an array 
void printArr(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Function to sort the array of 0s, 1s and 2s 
void sortArr(int arr[], int n) 
{ 
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0; 
  
    // Count the number of 0s, 1s and 2s in the array 
    for (i = 0; i < n; i++) { 
        switch (arr[i]) { 
        case 0: 
            cnt0++; 
            break; 
        case 1: 
            cnt1++; 
            break; 
        case 2: 
            cnt2++; 
            break; 
        } 
    } 
  
    // Update the array 
    i = 0; 
  
    // Store all the 0s in the beginning 
    while (cnt0 > 0) { 
        arr[i++] = 0; 
        cnt0--; 
    } 
  
    // Then all the 1s 
    while (cnt1 > 0) { 
        arr[i++] = 1; 
        cnt1--; 
    } 
  
    // Finally all the 2s 
    while (cnt2 > 0) { 
        arr[i++] = 2; 
        cnt2--; 
    } 
  
    // Print the sorted array 
    printArr(arr, n); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(int); 
  
    sortArr(arr, n); 
  
    return 0; 
} 