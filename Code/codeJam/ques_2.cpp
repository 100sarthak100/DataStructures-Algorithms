#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int testC = 0;
    while (t--)
    {
        testC++;
        string s, ret;
        cin >> s;
        stack<int> st;
        int prev, myint = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            int myint = s[j] - '0';
            //cout << myint << " " << prev << endl;
            if (st.empty() == true && myint != 0)
            {
                for (int i = 0; i < myint; ++i)
                {
                    st.push('(');
                    ret.push_back('(');
                }
                ret.push_back(s[j]);
                prev = myint;
            }
            else if (st.empty() == true && myint == 0 && s.size() > 1)
            {
                ret.push_back(s[j]);
                prev = myint;
            }

            else
            {
                if (myint < prev)
                {
                    for (int i = 0; i < prev - myint; ++i)
                    {
                        st.pop();
                        ret.push_back(')');
                    }
                    prev = myint;
                    ret.push_back(s[j]);
                }
                else if (myint > prev)
                {
                    for (int i = 0; i < myint - prev; ++i)
                    {
                        st.push('(');
                        ret.push_back('(');
                    }
                    prev = myint;
                    ret.push_back(s[j]);
                }
                else if (myint == prev)
                {
                    ret.push_back(s[j]);
                    prev = myint;
                }
            }
        }
        //cout << st.size() << endl;
        int siz = st.size();
        for (int i = 0; i < siz; ++i)
        {
            ret.push_back(')');
            st.pop();
        }
        //ret.push_back(')');
        cout << "Case #" << testC << ": " << ret << endl;
    }
}