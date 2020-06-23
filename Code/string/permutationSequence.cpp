// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"

// arr
// [ 1            2           3          4]
// 1 2 3 4     2 1 3 4     3 1 2 4    4 1 2 3
// 1 2 4 3     2 1 4 3     3 1 4 2    4 1 3 2
// 1 3 2 4     2 3 1 4     3 2 1 4    4 2 1 3
// 1 3 4 2     2 3 4 1     3 2 4 1    4 2 3 1
// 1 4 2 3     2 4 1 3     3 4 1 2    4 3 1 2
// 1 4 3 2     2 4 3 1     3 4 2 1    4 3 2 1
// So we have 4 block with 6 elements each.

// n = 4  we can take an array [1,2,3,4] , initital ans = ""
// lets say we have k =15, the 15 th permutation is "3 2 1 4":

// As we can see the first value is 3 that means out of the four blocks we need the 3rd block. 
// Each blocks has n-1! = 3! = 6 elements --> 15 = 6*2 + 3 i.e. we skip 2 blocks and our ans is the third element in the 3rd block
// Let us assume the blocks are zero indexed.
// Now 15 / 6 = 2;  So we select the 2nd block (0-indexed) that means 2nd index in our array - 3
// Now ans = "3"
// Remove this element from the array and our array becomes: [1,2,4]

class Solution {
public:
    void permut(vector<int> &val, string &ans, int n, int k, vector<int> &factVal)
    {
        if(n == 1)
        {
            ans += to_string(val.back());
            return;
        }
        
        int index = k/factVal[n-1];
        if(k % factVal[n-1] == 0)
            index--;
        
        ans += to_string(val[index]);
        val.erase(val.begin() + index);
        k -= factVal[n-1] * index;
        permut(val, ans, n-1, k, factVal);
    }
    
    
    string getPermutation(int n, int k) {
        if(n == 0)
            return "1";

        //vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        
        // factorial using dp
        vector<int> factVal(n+1);
        if(n >= 0)
        {
            factVal[0] = 1;
            for(int i=1; i<=n; i++)
                factVal[i] = i * factVal[i-1];
        }

        string ans = "";
        vector<int> val;
        for(int i=0; i<n ; i++)
            val.push_back(i+1);
        
        
        permut(val, ans, n, k, factVal);
        return ans;
    }
};