// Design a stack that supports push, pop, top, and retrieving 
// the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// time for min, max and peek - O(1)
// space - O(1) independently
// space - O(3N) -> O(N)

class MinStack {
public:
    stack<int> st;
    stack<pair<int, int>> minmaxst;
    MinStack() {
        while(!st.empty())
            st.pop();
        while(!minmaxst.empty())
            minmaxst.pop();
    }
    
    void push(int x) {
        st.push(x);
        if(minmaxst.empty())
            minmaxst.push({x, x});
        else
        {
            pair<int, int> p = minmaxst.top();
            if(x <= p.first)
                minmaxst.push({x, p.second});
            else if(x >= p.second)
                minmaxst.push({p.first, x});
            else
                minmaxst.push(p);
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop();
        minmaxst.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top();
    }
    
    int getMin() {
        if(minmaxst.empty())
            return -1;
        return minmaxst.top().first;
    }
};