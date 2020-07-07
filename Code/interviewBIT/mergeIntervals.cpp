// Given a set of non-overlapping intervals, insert a new interval 
// into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according 
// to their start times.

// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] 
// would result in [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],
// [8,10].

// Make sure the returned intervals are also sorted.

// Time - O(N)
bool comp(Interval a, Interval b)
 {
     return (a.start < b.start);
 }
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n = intervals.size();
    if(n == 0)
        return {newInterval};
        
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), comp);
    vector<Interval> ret;
    
    int index = 0;
    for(int i=1; i<n+1; i++)
    {
        if(intervals[index].end >= intervals[i].start)
        {
            intervals[index].start = min(intervals[index].start, intervals[i].start);
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        }
        else
        {
            index++;
            intervals[index] = intervals[i];
        }
    }
    
    for(int i=0; i<=index; i++)
        ret.push_back(intervals[i]);
        
    return ret;
}