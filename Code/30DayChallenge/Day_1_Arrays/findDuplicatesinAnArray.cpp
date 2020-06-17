// Given an array a[] of size N which contains elements from 0 to 
// N-1, you need to find 
// all the elements occurring more than once in the given array.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).
// space only for return vector , do only in O(1)

// Sample Input:
// 2
// 4
// 0 3 1 2
// 5
// 2 3 1 2 3 

// Sample Output:
// -1
// 2 3 

// Explanation:
// Testcase 1: N=4 and all elements from 0 to (N-1 = 3) are present in the given array. Therefore output is -1.
// Testcase 2: 2 and 3 occur more than once in the given array.

vector<int> duplicates(int a[], int n) {
    vector<int> ret;
    if(n == 0) return ret;
    for(int i = 0; i<n; i++)
    {
        a[a[i] % n] += n;
    }
    
    for(int i = 0; i<n; i++)
    {
        //cout<<a[i]<<" "<<a[i]/n<<endl;
        if(a[i]/n > 1)
            ret.push_back(i);
    }
    if(ret.empty())
        ret.push_back(-1);
    return ret;
}