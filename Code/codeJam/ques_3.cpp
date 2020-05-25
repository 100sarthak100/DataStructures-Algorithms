#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;
typedef pair<int, char> pairs2;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n;
        set<pairs> s;
        set<pairs2> st;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            s.insert(make_pair(a, b));
        }
        set<pairs>::iterator itr = s.begin();
        int start = itr->first;
        int end = itr->second;
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            auto itr2 = std::next(itr, 1);
            if (itr->second > itr2->first && st.empty() == true)
            {
                cout << "J";
                st.insert(make_pair(itr->second, 'J'));
            }
            else if (itr->second < itr2->first && st.empty() == true)
            {
                cout << "J";
                st.insert(make_pair(itr->second, 'J'));
            }
            else if (!st.empty() && itr->second > itr2->first)
            {
                auto stitr = st.begin();
                if (stitr->first == 'J' && stitr->second > itr->second)
                {
                    cout << "C";
                    st.insert(make_pair(itr->second, 'C'));
                }
            }
            else if (!st.empty() && itr->second < itr2->first)
            {
                        }
        }
    }
}