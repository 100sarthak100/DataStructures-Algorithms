string isBalanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if ((s[i] == ')' || s[i] == '}' || s[i] == ']') && st.empty() == true)
            return "NO";
        else if (s[i] == ')' && st.top() == '(')
            st.pop();
        else if (s[i] == '}' && st.top() == '{')
            st.pop();
        else if (s[i] == ']' && st.top() == '[')
            st.pop();
        else
            return "NO";
    }
    if (!st.empty())
        return "NO";
    else
        return "YES";
}