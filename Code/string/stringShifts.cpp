// Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
// Output: "efgabcd"
// Explanation:
// [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
// [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
// [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
// [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int total = 0;
        for (vector<int> pp : shift)
        {
            if (pp[0] == 0)
                total -= pp[1];
            else
                total += pp[1];
        }
        int n = s.size();
        cout << total << endl;
        total %= n;
        cout << total << endl;
        if (total < 0)
            total += n;
        cout << total << endl;
        return s.substr(n - total) + s.substr(0, n - total);
    }
};