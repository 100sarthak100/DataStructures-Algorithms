// Example 1:

// Input: "banana"
// Output: "ana"
// Example 2:

// Input: "abcd"
// Output: ""

// time - O(n logn)

class Solution {
public:
    int prime = 10000007; // should be large to avoid collisions
    vector<int> power;
    
    string rabinKarp(string s, int len)
    {
        if(len == 0)
            return "";
        int n = s.size(), curr = 0;
        // map hash values to start index of substrings with that hash value (same hash values for different             // substrings can occur)
        unordered_map<int, vector<int>> hash;
        
        // compute hash value for first 'len' characters
        for(int i = 0; i<len; i++)
            curr = (curr * 26 + (s[i] - 'a'))%prime;
        
        // map this initial hash value with index 0 (means substring of lenght 'len' starting at index 0)
        hash[curr] = {0};
        
        for(int i = len; i<n; i++)
        {
            // sliding window to maintain current substring's hash
            curr = ((curr - power[len - 1] * (s[i - len] - 'a'))%prime + prime)%prime;
            curr = (curr*26 + (s[i] - 'a'))%prime;
            
            // if this new hash does not exist in map then store it with the new start index (i-len+1)
            if(hash.find(curr) == hash.end())
                hash[curr] = {i - len + 1};
            // if hash already exists in map then for all start indices check if any substrings match with the               // current window of substr.
            else
            {
                for(auto index : hash[curr])
                    if(s.substr(index, len) == s.substr(i - len + 1, len))
                        return s.substr(index, len);
            }
             // if none matches (happens when different substrings have same hash value) simply map this new                  // start index for current window to this hash value
            hash[curr].push_back({i-len+1});
        }
        return "";      // if no duplicates exist
    }
    
    string longestDupSubstring(string S) {
        int n = S.size();
        // pre-compute all pow(26, k), 0 < k < n module prime for rolling hash
        power = vector<int>(n);
        for(int i = 0; i<n; i++)
            power[i] = (i == 0) ? 1 : (power[i-1]*26)%prime;
        
        int l = 0, r = n - 1;
        string res = "";
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            string dup = rabinKarp(S, mid);
            if(dup.size() > res.size())
            {
                res = dup;
                l = mid + 1; 
            }
            else
                r = mid - 1;
        }
        return res;
    }
};