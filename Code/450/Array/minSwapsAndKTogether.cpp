// Given an array of n positive integers and a number k. Find the 
// minimum number of swaps required to bring all the numbers less 
// than or equal to k together.

// Example 1:

// Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
// Output : 1
// Explanation:
// To bring elements 2, 1, 3 together, swap element '5' with '3'
// such that final array will be- arr[] = {2, 1, 3, 6, 5}

// Example 2:

// Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
// Output :  2 

// Time - O(n)
// Space - O(1)

int minSwap(int *arr, int n, int k) {
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] <= k)
            count++;
    }
    
    int bad = 0;
    for(int i=0; i<count; i++)
        if(arr[i] > k)
            bad++;
    
    int start = 0, end = count;
    int minbad = bad;
    while(end < n)
    {
        // cout<<start<<" "<<end<<endl;
        if(arr[start] > k)
            bad--;
        
        if(arr[end] > k)
            bad++;
        
        if(bad == n)
        {
            minbad = 0;
            break;
        }
        // cout<<bad<<endl;
        minbad = min(minbad, bad);
        start++;
        end++;
    }
    
    return minbad;
}