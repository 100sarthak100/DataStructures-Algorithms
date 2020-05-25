class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        vector<vector<string>> ret;
        if(strs.size() == 0) return ret;
        for(string s : strs)
        {
            string sorted = s;
            sort(sorted.begin(),sorted.end());
            m[sorted].push_back(s);
        }
        for(auto x : m)
            ret.push_back(x.second);
        return ret;
    }
};