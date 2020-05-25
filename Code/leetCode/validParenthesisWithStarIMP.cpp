// Input: "(*))"
// Output: True

class Solution
{
public:
    bool checkValidString(string s)
    {
        int balance = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '*')
                balance++;
            else if (--balance == -1)
                return false;
        }
        balance = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')' || s[i] == '*')
                balance++;
            else if (--balance == -1)
                return false;
        }
        return true;
    }
};