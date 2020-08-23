// Given an array of 0s and 1s. Find the length of the largest 
// subarray with equal number of 0s and 1s.

// Input
// 2
// 4
// 0 1 0 1
// 5
// 0 0 1 0 0

// Output
// 4
// 2

// Explanation:
// Testacase 1: The array from index [0...3] contains equal 
// number of 0's and 1's. Thus maximum length 
// of subarray having equal number of 0's and 1's is 4.

// time - O(N)
// Space - O(N)

int maxLen(int arr[], int N)
{
    unordered_map<int, int> mp;
    int maxVal = 0;
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        sum += (arr[i] == 0 ? -1 : 1);
        
        if(sum == 0)
            maxVal = max(maxVal, i+1);
            
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
        else
            maxVal = max(maxVal, i - mp[sum]);
    }
    return maxVal;
}