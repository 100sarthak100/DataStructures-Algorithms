// Given an array of integers and a number K. Find the count of 
// distinct elements in every window of size K in the array.

// Sample Input:
// 2
// 7 4
// 1 2 1 3 4 2 3
// 3 2
// 4 1 1

// Sample Output:
// 3 4 4 3
// 2 1

// Explanation:
// Testcase 1 : 
// Window 1 of size k = 4 is 1 2 1 3. Number 
// of distinct elements in this window are 3. 
// Window 2 of size k = 4 is 2 1 3 4. Number of 
// distinct elements in this window are 4.
// Window 3 of size k = 4 is 1 3 4 2. Number of 
// distinct elements in this window are 4.
// Window 4 of size k = 4 is 3 4 2 3. Number of 
// distinct elements in this window are 3.

// Time complexity O(n). As single traversal of the array is required.
// Space Compelxity O(n). Since, the hashmap requires linear space.

// showing tle
// working with unordered_map
// can also work with simple array
vector <int> countDistinct (int A[], int n, int k)
{
    map<int, int> hm;
    int dist_count = 0;
    vector<int> ret;
    if(n == 0 || k <= 0)
        return ret;
    
    for(int i=0; i<k; i++)
    {
        if(hm[A[i]] == 0)
            dist_count++;
        hm[A[i]]++;
    }
    
    ret.push_back(dist_count);
    
    for(int i=k; i<n; i++)
    {
        if(hm[A[i-k]] == 1)
            dist_count--;
        hm[A[i-k]]--;
        
        if(hm[A[i]] == 0)
            dist_count++;
        hm[A[i]]++;
        
        ret.push_back(dist_count);
    }
    
    return ret;
}