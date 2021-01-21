// Given an array, find the nearest smaller element G[i] for every 
// element A[i] in the array such 
// that the element has an index smaller than i.

// For Example

// Input 1:
//     A = [4, 5, 2, 10, 8]
// Output 1:
//     G = [-1, 4, -1, 2, 2]
// Explaination 1:
//     index 1: No element less than 4 in left of 4, G[1] = -1
//     index 2: A[1] is only element less than A[2], G[2] = A[1]
//     index 3: No element less than 2 in left of 2, G[3] = -1
//     index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
//     index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
// Input 2:
//     A = [3, 2, 1]
// Output 2:
//     [-1, -1, -1]
// Explaination 2:
//     index 1: No element less than 3 in left of 3, G[1] = -1
//     index 2: No element less than 2 in left of 2, G[2] = -1
//     index 3: No element less than 1 in left of 1, G[3] = -1

// Time - O(N)
// Space - O(N) -> stack

// Also called as Next Smallest to left
// Next smallest to right is same, start from the end;

vector<int> Solution::prevSmaller(vector<int> &arr) {
    vector<int> vec;
	stack<int> s;
	int n = arr.size();
	    
	for(int i=0; i<n; i++)
	{
	   if(s.size() == 0)
	        vec.push_back(-1);
	   else if(s.size() > 0 && s.top() < arr[i])
	        vec.push_back(s.top());
	   else if(s.size() > 0 && s.top() >= arr[i])
	   {
	        while(s.size() > 0 && s.top() >= arr[i])
	           s.pop();
	                
	        if(s.size() == 0)
	           vec.push_back(-1);
	        else
	           vec.push_back(s.top());
	   }
	        
	   s.push(arr[i]);
	 }
	    
	 return vec;
}