#include <bits/stdc++.h>
using namespace std;

struct myStack
{
    stack<int> s;
    int minEle;

    void getMin()
    {
        if (s.empty())
            cout << "stack is empty" << endl;
        else
        {
            cout << minEle << endl;
        }
    }

    void peek()
    {
        if (s.empty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        int t = s.top();
        (t < minEle) ? cout << minEle : cout << t;
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        int t = s.top();
        s.pop();
        if (t < minEle)
        {
            cout << minEle << endl;
            minEle = 2 * minEle - t;
        }
        else
            cout << t << endl;
    }
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout << "no pushed " << x << endl;
            return;
        }
        if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);
        cout << "no inserted is " << x << endl;
    }
};

int main()
{
    myStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
}

// alternate version
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minst;
    MinStack()
    {
        while (!minst.empty())
            minst.pop();
        while (!st.empty())
            st.pop();
    }

    void push(int x)
    {
        st.push(x);
        if (minst.empty() == true)
            minst.push(x);
        else
        {
            if (x <= minst.top())
                minst.push(x);
            else
                minst.push(minst.top());
        }
    }

    void pop()
    {
        if (st.empty() == true)
            return;
        st.pop();
        minst.pop();
    }

    int top()
    {
        if (st.empty() == true)
            return -1;
        else
            return st.top();
    }

    int getMin()
    {
        if (minst.empty())
            return -1;
        return minst.top();
    }
};