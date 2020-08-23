// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

class Solution {
public:
    bool static comp(const vector<int> &a1, const vector<int> &a2)
    {
        return (a1[0] < a2[0]);   
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        int j = 0,i;
        for(i=1; i<n; i++)
        {
            if(intervals[j][1] >= intervals[i][0])
            {
                intervals[j][0] = min(intervals[j][0], intervals[i][0]);
                intervals[j][1] = max(intervals[j][1], intervals[i][1]); 
            }
            else
            {
               if(j < i)
               {
                   j++;
                   intervals[j] = intervals[i];
               }
            }
        }
        for(int x=n-1; x>j; x--)
            intervals.pop_back();
        
        return intervals;
    }
};