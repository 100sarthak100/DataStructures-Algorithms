// Given a binary string s (a string consisting only of '0's and 
// '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+ 
// s2+ s3 = s).

// Return the number of ways s can be split such that the number 
// of characters '1' is the same in s1, s2, and s3.

// Since the answer may be too large, return it modulo 10^9 + 7.

// Example 1:

// Input: s = "10101"
// Output: 4
// Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
// "1|010|1"
// "1|01|01"
// "10|10|1"
// "10|1|01"
// Example 2:

// Input: s = "1001"
// Output: 0
// Example 3:

// Input: s = "0000"
// Output: 3
// Explanation: There are three ways to split s in 3 parts.
// "0|0|00"
// "0|00|0"
// "00|0|0"
// Example 4:

// Input: s = "100100010100110"
// Output: 12

// Time - o(N)
// Space - o(N)

class Solution {
public:
    long long mod = 10e8+7;
    
    //  O(k) time and O(1) extra space.
    long long binomialCoeff(long long n, long long k)
    {
        if(k > n-k)
            k = n - k;
        
        long long res = 1;
        for(int i=0; i<k; i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    
    // O(N)
    int numWays(string s) {
        int n = s.size();
        long long oneCount = 0;
        for(int i=0; i<n; i++)
            if(s[i] == '1')
                oneCount++;
        
        if(oneCount%3 != 0)
            return 0;
        
        if(oneCount == 0)
            return binomialCoeff(n-1, 2)%mod;
        
        vector<long long> ret;
        
        long long zeroCount = 0, count = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '1')
                count++;
            
            if(count == oneCount/3 && s[i] == '0')
                zeroCount++;
            
            if(count > oneCount/3)
            {
                ret.push_back(zeroCount);
                zeroCount = 0;
                count = 1;
            }
        }
        long long ans = 1;
        for(int i=0; i<ret.size(); i++)
            ans = (ans%mod * (ret[i]+1)%mod)%mod;
        
        return (ans%mod);
    }
};