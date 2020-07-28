// Given an input stream of N integers. The task is to insert 
// these numbers into a new stream and find the median of the 
// stream formed by each insertion of X to the new stream.

// For each element added to the stream print the floor of the 
// new median in a new line.

// Input:
// 4
// 5
// 15
// 1 
// 3
// Output:
// 5
// 10
// 5
// 4
 
// Explanation:
// Testcase 1:
// Flow in stream : 5, 15, 1, 3
// 5 goes to stream --> median 5 (5)
// 15 goes to stream --> median 10 (5, 15)
// 1 goes to stream --> median 5 (5, 15, 1)
// 3 goes to stream --> median 4 (5, 15, 1, 3)

// Time Complexity: O(n Log n)
// Auxiliary Space : O(n)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;
     
	int n;cin>>n;
	
	double x;cin>>x;
	double med = x;
	n--;
	s.push(med);
	cout<<(int)med<<endl;
	
	while(n--)
	{
	    cin>>x;
	    
	    if(s.size() > g.size())
	    {
	        if(x < med)
	        {
	            g.push(s.top());
	            s.pop();
	            s.push(x);
	        }
	        else
	            g.push(x);
	       
	       med = (s.top() + g.top())/2.0;
	    }
	    else if(s.size() == g.size())
	    {
	        if(x < med)
	        {
	            s.push(x);
	            med = (double)s.top();
	        }
	        else
	        {
	            g.push(x);
	            med = (double)g.top();
	        }
	    }
	    else
	    {
	        if(x > med)
	        {
	            s.push(g.top());
	            g.pop();
	            g.push(x);
	        }
	        else
	            s.push(x);
	       
	       med = (s.top() + g.top())/2.0;
	    }
	    
	    cout<<(int)med<<endl;
	}
	return 0;
}