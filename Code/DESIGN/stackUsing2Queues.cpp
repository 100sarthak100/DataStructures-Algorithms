#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q1, q2;
    int currSize;

    public:
    Stack()
    {
        currSize = 0;
    }

    void push(int x)
    {
        currSize++;
        q2.push(x);

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
        return;
    }

    void pop()
    {
        if(q1.empty())
            return;
        q1.pop();
        currSize--;
    }

    int top()
    {
        if(q1.empty())
            return -1;
        int x = q1.front();
        return x;
    }

    int size()
    {
        return currSize;
    }

};

int main()
{
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
    cout << "current size: " << s.size() 
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
  
    cout << "current size: " << s.size() 
         << endl; 
    return 0; 
}