// Design a data-structure SpecialStack that supports 
// all the stack operations like push(), pop(), isEmpty(), isFull() 
// and an additional operation getMin() which should return minimum 
// element from the SpecialStack. Your task is to complete all the 
// functions, using stack data-Structure.

// Example 1:

// Input:
// Stack: 18 19 29 15 16
// Output: 15
// Explanation:
// The minimum element of the stack is 15.

// Time - O(1)
// Space - O(1)

int minEle;

void push(stack<int>& s, int a){
	if(s.size() == 0)
	{
	    s.push(a);
	    minEle = a;
	}
	else
	{
	    if(a >= minEle)
	        s.push(a);
	    else if(a < minEle)
	    {
            // 2*3 - 5 (6 - 5) => 1
	        s.push(2*a - minEle);
	        minEle = a;
	    }
	}
	return;
}

bool isFull(stack<int>& s,int n){
	if(s.size() == n)
	    return true;
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.size() == 0)
	    return true;
	 return false;
}

int pop(stack<int>& s){
	if(s.size() == 0)
	    return -1;
	else
	{
	    if(s.top() >= minEle)
	    {
	        int a = s.top();
	        s.pop();
	        return a;
	    }
	    else if(s.top() < minEle)
	    {
	        int a = minEle;
            // (2*3 - 1) => 5
	        minEle = 2*minEle - s.top();
	        s.pop();
	        return a;
	    }
	}
	
	return -1;
}

int getMin(stack<int>& s){
	if(s.size() == 0)
	    return -1;
	return minEle;
}