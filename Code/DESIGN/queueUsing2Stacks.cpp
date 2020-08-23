// Time Complexity:
// Push operation: O(N).
// In the worst case we have empty whole of 
// stack 1 into stack 2.
// Pop operation: O(1).
// Same as pop operation in stack.
// Auxiliary Space: O(N).
// Use of stack for storing values.

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return;
    }

    int deQueue()
    {
        if(s1.empty())
            return -1;
        
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
  
    return 0; 
}