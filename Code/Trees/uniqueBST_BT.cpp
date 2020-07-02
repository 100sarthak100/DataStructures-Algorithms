// Given n, how many structurally unique BST's (binary search 
// trees) that store values 1 ... n?

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

// Count of BST with 5 nodes is 42
// Count of binary trees with 5 nodes is 5040

#include <bits/stdc++.h>
using namespace std;

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    if(k > n - k)
        k = n - k;

    unsigned long int res = 1;
    for(int i = 0; i<k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

unsigned int long catalan(unsigned int n)
{
    unsigned long int c = binomialCoeff(2*n, n);
    return c/(n + 1);
}

unsigned long int factorial(unsigned int n)
{
    unsigned long int res = 1;
    for(int i=1; i<=n; i++)
    {
        res = res * i;
    }
    return res;
}

int main()
{
    int n = 5;
    cout<<"number of unique BT : "<< catalan(n) * factorial(n)<<endl;
}