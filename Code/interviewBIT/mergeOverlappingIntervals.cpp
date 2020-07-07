// Given a collection of intervals, merge all overlapping intervals.

// For example:

// Given [1,3],[2,6],[8,10],[15,18],

// return [1,6],[8,10],[15,18].

// Make sure the returned intervals are sorted.

bool comp(Interval a, Interval b)
 {
     return (a.start < b.start);
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    
    if(n == 0)
        return {};
    
    sort(A.begin(), A.end(), comp);
    int index = 0;
    for(int i=1; i<n; i++)
    {
        if(A[index].end >= A[i].start)
        {
            A[index].start = min(A[index].start, A[i].start);
            A[index].end = max(A[index].end, A[i].end);
        }
        else
        {
            index++;
            A[index] = A[i];
        }
    }
    
    for(int i = n-1; i>index; i--)
        A.pop_back();
    
    return A;
}