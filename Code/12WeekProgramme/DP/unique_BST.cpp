// Given n, how many structurally unique BST's (binary search trees) 
// that store values 1 ... n?

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
public:
    unsigned long int binomialCoeff(unsigned int n, unsigned int k)
    {
        if(k > n - k)
            k = n - k;
        
        unsigned long int  res = 1;
        for(int i = 0; i<k; i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        
        return res;
    }
    
    
    unsigned long int catalan(unsigned int n)
    {
        unsigned long int c = binomialCoeff(2*n, n);
        return c/(n + 1);
    }
    
    
    int numTrees(int n) {
        return catalan(n);
    }
};