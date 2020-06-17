#include <bits/stdc++.h>
using namespace std;

bool powerTwo(int n)
{
    return n&(n-1);
}

int main()
{
    int n = 8;
    if(powerTwo(n))
        cout<<"Not a power of two";
    else cout<<"power of two"<<endl;
}

// method 2 , with signed integer overflow detect
// Input: 16
// Output: true
// Explanation: 24 = 16

class Solution {
public:
    // Implementation of Brian Kernighan’s Algorithm:
    // to dtect bit set count
    // for number of poer of two bit set count is always 1
    // Time Complexity: O(logn)
    unsigned int countSet(int n)
    {
        unsigned int count = 0;
        while(n)
        {
            if(n < 0)
                break;
            n &= (n - 1);
            count++;       
        }
        return count;
    }
    bool isPowerOfTwo(int n) {
        unsigned int a = countSet(n);
        if(a == 1)
            return true;
        else return false;
    }
};