// Find the largest rectangular area possible in a given histogram where 
// the largest rectangle can be made of a number of contiguous bars. 
// For simplicity, assume that all bars have the same width and the 
// width is 1 unit.

// Example 1:

// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12

// Example 2:

// Input:
// N = 8
// arr[] = {7 2 8 9 1 3 6 5}
// Output: 16
// Explanation: Maximum size of the histogram 
// will be 8  and there will be 2 consecutive 
// histogram. And hence the area of the 
// histogram will be 8x2 = 16.

// Time - O(N)
// Space - O(N)

// using both NSL & NSR

void nearestSmallestLeft(vector<long long> &nsl, long long arr[], int n)
{
    stack<pair<long long, int>> s;
    
    for(int i=0; i<n; ++i)
    {
        if(s.size() == 0)
            nsl.push_back(-1);
        else if(s.size() > 0 && s.top().first < arr[i])
            nsl.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i])
        {
            while(s.size() > 0 && s.top().first >= arr[i])
                s.pop();
                
            if(s.size() == 0)
                nsl.push_back(-1);
            else
                nsl.push_back(s.top().second);
        }
        
        s.push({arr[i], i});
    }
    
    return;
}

void nearestSmallestRight(vector<long long> &nsr, long long arr[], int n)
{
    stack<pair<long long, int>> s;
    
    for(int i=n-1; i>=0; --i)
    {
        if(s.size() == 0)
            nsr.push_back(n);
        else if(s.size() > 0 && s.top().first < arr[i])
            nsr.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i])
        {
            while(s.size() > 0 && s.top().first >= arr[i])
                s.pop();
                
            if(s.size() == 0)
                nsr.push_back(n);
            else
                nsr.push_back(s.top().second);
        }
        
        s.push({arr[i], i});
    }
    
    reverse(nsr.begin(), nsr.end());
    
    return;
}


long long getMaxArea(long long arr[], int n){
    
    vector<long long> nsl, nsr, width, area;
    long long maxArea = 0;
    
    nearestSmallestLeft(nsl, arr, n);
    nearestSmallestRight(nsr, arr, n);
    // for(int i=0; i<n; i++)
    //     cout<<nsr[i]<<" ";
    // cout<<endl;
    // for(int i=0; i<n; i++)
    //     cout<<nsl[i]<<" ";
    // cout<<endl;
    
    for(int i=0; i<n; i++)
        width.push_back(nsr[i] - nsl[i] - 1);
    
    for(int i=0; i<n; i++)
        area.push_back(arr[i] * width[i]);
        
    for(int i=0; i<n; i++)
        maxArea = max(maxArea, area[i]);
        
    return maxArea;
}