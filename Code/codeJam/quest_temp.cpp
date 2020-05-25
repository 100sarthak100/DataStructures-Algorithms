#include <bits/stdc++.h>
using namespace std;

bool sortByLogic(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    return (a.second.second < b.second.second);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> vec(n);
        for (int i = 1; i <= n; i++)
        {
            vec[i - 1].first = i;
            cin >> vec[i - 1].second.first;
            cin >> vec[i - 1].second.second;
        }

        sort(vec.begin(), vec.end(), sortByLogic);
        for (auto x : vec)
        {
            cout << x.first << " -> " << x.second.first << " " << x.second.second << endl;
        }
        int i = 0;
        int count = 1;
        //cout<<vec[i].first<<" ";
        char prev = 'J';
        for (int j = 1; j < n; j++)
        {
            if (vec[j].second.first >= vec[i].second.second)
            {
                if (prev == 'J')
                {
                    cout << "C";
                    cout << 'J';
                    i = j;
                    prev = 'J';
                }
                else
                {
                    cout << 'J';
                    cout << 'C';
                    i = j;
                    prev = 'C';
                }
            }
            else
            {
                if (prev == 'C')
                    cout << "J";
                else
                {
                    cout << 'C';
                    prev = 'C';
                }
            }
        }
    }
    return 0;
}
