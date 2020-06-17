// Input:
// 3
// 5 3
// 1 2 3 4 5
// 1 2 3
// 5 5
// 2 2 3 4 5
// 1 1 2 3 4
// 5 5
// 1 1 1 1 1
// 2 2 2 2 2
// Output:
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2

// Explanation:
// Testcase 1: Distinct elements including both the arrays are: 1 2 3 4 5.
// Testcase 2: Distinct elements including both the arrays are: 1 2 3 4 5.
// Testcase 3: Distinct elements including both the arrays are: 1 2.

// Expected Time Complexity: O(N+M).
//Expected Auxiliary Space: O(N+M).
// but here im also using sort fn so have to check the final complexity

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ret;
    int ans[1000001];
    memset(ans, 0, sizeof(ans));
    ret.push_back(arr1[0]);
    ans[arr1[0]]++;
    
    for(int i = 1; i<n; i++)
    {
        if(arr1[i-1] != arr1[i])
        {
            ans[arr1[i]]++;
            ret.push_back(arr1[i]);
        }
    }
    
    for(int i= 0; i<m; i++)
    {
        if(ans[arr2[i]] == 0)
        {
            ans[arr2[i]]++;
            ret.push_back(arr2[i]);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}