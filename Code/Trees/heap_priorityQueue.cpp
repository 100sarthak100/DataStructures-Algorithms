#include <bits/stdc++.h>
using namespace std;

void push_pq(priority_queue<int, vector<int>, greater<int>> &pq, int x)
{
    pq.push(x);
    return;
}

void pp_pq(priority_queue<int, vector<int>, greater<int>> &pq)
{
    if (!pq.empty())
        pq.pop();
    else
        return;
}

int pq_top(priority_queue<int, vector<int>, greater<int>> &pq)
{
    if (!pq.empty())
        return pq.top();
    else
    {
        return -1;
    }
}

int main()
{
    int t, q, num;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> q;
        for (int j = 0; j < q; ++j)
        {
            string s;
            cin >> s;
            if (s == "p")
            {
                cin >> num;
                push_pq(pq, num);
                cout << pq.size() << endl;
            }
            if (s == "pp")
            {
                pp_pq(pq);
                cout << pq.size() << endl;
            }
            if (s == "t")
            {
                cout << pq_top(pq) << endl;
                ;
            }
        }
    }
}