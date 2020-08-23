// Given an array of integers, sort the array 
// according to frequency of elements. That is 
// elements that have higher frequency come first. 
// If frequencies of two elements are same, then 
// smaller number comes first.

// Example 1:

// Input:
// N = 5
// A[] = {5,5,4,6,4}
// Output: 4 4 5 5 6
// Explanation: The highest frequency here is
// 2. Both 5 and 4 have that frequency. Now
// since the frequencies are same then 
// smallerelement comes first. So 4 4 comes 
// firstthen comes 5 5. Finally comes 6.
// The output is 4 4 5 5 6.
// Example 2:

// Input:
// N = 5
// A[] = {9,9,9,2,5}
// Output: 9 9 9 2 5
// Explanation: The highest frequency here is
// 3. The element 9 has the highest frequency
// So 9 9 9 comes first. Now both 2 and 5
// have same frequency. So we print smaller
// element first.
// The output is 9 9 9 2 5.

// Time Complexity : O(n) + O(m Log m) where n is total number of 
// elements and m is total number of distinct elements

// We insert all elements and their counts into a hash. This step 
// takes O(n) time where n is number of elements.
// We copy contents of hash to an array (or vector) and sort them by 
// counts. This step takes O(m Log m) time where m is total number of 
// distinct elements.
// For maintaining the order of elements if the frequency is same,we 
// use another hash which has the key as elements of the array and 
// value as the index. If the frequency is same for 
// two elements then sort elements according to the index.

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second == p2.second)
        return (p1.first < p2.first);
    
    return (p1.second > p2.second);
}

vector<int> sortByFreq(int arr[],int n)
{
    unordered_map<int, int> m1;
    for(int i=0; i<n; i++)
        m1[arr[i]]++;
    
    vector<pair<int, int>> vec;
    
    for(auto i : m1)
    {
        vec.push_back({i.first, i.second});
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    vector<int> ret;
    
    for(int i=0; i<vec.size(); i++)
    {
        for(int j=0; j<vec[i].second; j++)
            ret.push_back(vec[i].first);
    }
    return ret;
}