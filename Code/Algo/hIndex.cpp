// array is not sorted before, have to sort it in O(nlog n)
// using quick sort
// then traverse the array in O(n)

// Input: citations = [3,0,6,1,5]
// Output: 3 
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in 
//              total and each of them had 
//              received 3, 0, 6, 1, 5 citations respectively. 
//              Since the researcher has 3 papers with at least 3 
//              citations each and the remaining two with no more 
//              than 3 citations each, her h-index is 3.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int cnt = 0;
        for(int i = n-1; i>=0; i--)
        {
            cnt++;
            if(citations[i] < cnt)
                return cnt - 1;
        }
        return cnt;
    }
};

// now array is already sorted, so using binary search 
// time - O(log n);

// Input: citations = [0,1,3,5,6]
// Output: 3 
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
//              received 0, 1, 3, 5, 6 citations respectively. 
//              Since the researcher has 3 papers with at least 3 citations each and the remaining 
//              two with no more than 3 citations each, her h-index is 3.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(citations[mid] >= n - mid)
            {
                ans = n - mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

// O(n) approach with sorted array

// This approach is straight forward traverse the array and when 
// you find the first element such that the value of that element
// is greater than or equal to the amount of elements remaining 
// that is our ans so we return the length of array after that
// point. If no such element exisits return 0;

int hIndex(int c[], int n)
{
    if(n == 0)
        return 0;
    for(int i = 0; i<n; i++)
    {
        if(c[i] >= n - i)
            return n - i;
    }
    return 0;
}