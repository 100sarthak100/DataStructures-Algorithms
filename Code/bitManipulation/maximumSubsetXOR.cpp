// Input: set[] = {2, 4, 5}
// Output: 7
// The subset {2, 5} has maximum XOR value

// Input: set[] = {9, 8, 5}
// Output: 13
// The subset {8, 5} has maximum XOR value

// Input: set[] = {8, 1, 2, 12, 7, 6}
// Output: 15
// The subset {1, 2, 12} has maximum XOR value

// Input: set[] = {4, 6}
// Output: 6
// The subset {6} has maximum XOR value


#include <bits/stdc++.h>
using namespace std;
#define INT_BITS 32

int maxSubarrayXOR(int set[], int n)
{
    int index = 0;
    for(int i = INT_BITS-1; i >= 0; i--)
    {
        int maxInd = index;
        int maxEle = INT_MIN;

        for(int j = index; j < n;j++)
        {
            if( (set[j]&(1<<i)) != 0
            && set[j] > maxEle)
            {
            maxEle = set[j];
            maxInd = j;
            }
        }

        if(maxEle == INT_MIN)
            continue;

        swap(set[index], set[maxInd]);
        maxInd = index;

        for(int j = 0;j<n;j++)
        {
            if(j != maxInd
            && (set[j]&(1<<i)) != 0)
            set[j] = set[j] ^ set[maxInd];
        }
        index++;
    }
    int res = 0;
    for(int i = 0;i<n;i++)
        res ^= set[i];
    return res;
}

int main()
{
    int set[] = {9, 8, 5}; 
    int n = sizeof(set) / sizeof(set[0]); 
      
    cout << "Max subset XOR is "; 
    cout << maxSubarrayXOR(set, n); 
    return 0; 
}