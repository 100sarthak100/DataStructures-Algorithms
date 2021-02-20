// Given an array of integers A. There is a sliding window of size k which
// is moving from the very left of the array to the very right.
// You can only see the w numbers in the window. Each time the sliding 
// window moves
// rightwards by one position. You have to find the maximum for each 
// window.The following example will give you more clarity.

// The array A is [1 3 -1 -3 5 3 6 7], and k is 3.

// Input 1:
//     A = [1, 3, -1, -3, 5, 3, 6, 7]
//     B = 3
// Output 1:
//     C = [3, 3, 5, 5, 6, 7]

// Time - O(N)
// Space - O(K)

// Also called as sliding window maximum (!!! Important !!!)

vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> v;
    int i = 0, j = 0;
    
    while(j < arr.size())
    {
        while(dq.size() > 0 && dq.back() < arr[j])
            dq.pop_back();
        dq.push_back(arr[j]);
        
        if(j - i + 1 < k)
            j++;
        else if(j - i + 1 == k)
        {
            v.push_back(dq.front());
            if(dq.front() == arr[i])
                dq.pop_front();
            i++;
            j++;
        }
    }
    return v;
}