#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct mystack
{
    stack<ll> s;
    ll maxEle;

    void getMax()
    {
        if (s.empty() == true)
            cout << "stack is empty" << endl;
        else
            cout << maxEle << endl;
    }

    void peek()
    {
        if (s.empty())
        {
            cout << "stack is empty";
            return;
        }
        if (s.top() > maxEle)
            cout << maxEle << endl;
        else
            cout << s.top() << endl;
    }

    void pop()
    {
        if (s.empty())
            return;
        ll t = s.top();
        s.pop();
        if (t > maxEle)
        {
            cout << "pop: " << maxEle << endl;
            maxEle = 2 * maxEle - t;
        }
        else
            cout << "pop: " << t << endl;
    }

    void push(ll x)
    {
        if (s.empty())
        {
            maxEle = x;
            s.push(x);
            return;
        }
        if (x > maxEle)
        {
            s.push(2 * x - maxEle);
            maxEle = x;
        }
        else
            s.push(x);
    }
};

int main()
{
    mystack s;
    s.push(97);
    s.pop();
    s.push(20);
    s.pop();
    s.push(26);
    s.push(20);
    s.pop();
    s.getMax();
    s.push(91);
    s.getMax();
}