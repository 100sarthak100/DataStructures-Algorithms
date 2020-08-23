// Given K sorted arrays arranged in the form of a matrix 
// of size K*K. The task is to merge them into one sorted array.
// Example 1:

// Input:
// K = 3
// arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation:Above test case has 3 sorted
// arrays of size 3, 3, 3
// arr[][] = [[1, 2, 3],[4, 5, 6], 
// [7, 8, 9]]
// The merged list will be 
// [1, 2, 3, 4, 5, 6, 7, 8, 9].
// Example 2:

// Input:
// K = 4
// arr[][]={{1,2,3,4}{2,2,3,4},
//          {5,5,6,6},{7,8,9,9}}
// Output:
// 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
// Explanation: Above test case has 4 sorted
// arrays of size 4, 4, 4, 4
// arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
// [5, 5, 6, 6]  [7, 8, 9, 9 ]]
// The merged list will be 
// [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
// 6, 6, 7, 8, 9, 9 ].

// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)

typedef pair<int, pair<int, int>> p;
int *mergeKArrays(int arr[][N], int k)
{
    int *ret = new int[k*N]; 
    priority_queue<p, vector<p>, greater<p>> pq;
    for(int i=0; i<k; i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    int j = 0;
    while(!pq.empty())
    {
        pair<int, pair<int, int>> pr = pq.top();
        pq.pop();
        ret[j] = pr.first;
        j++;
        int arrNum = pr.second.first;
        int eleNum = pr.second.second;
        if(eleNum < k-1)
        {
            pq.push({arr[arrNum][eleNum+1], {arrNum, eleNum+1}});
        }
    }
    return ret;
}