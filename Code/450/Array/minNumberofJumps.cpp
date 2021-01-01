// Given an array of integers where each element represents the
//  max number of steps that can be made forward from that element. 
//  The task is to find the minimum number of jumps to reach the end 
//  of the array (starting from the first element). If an element is 
//  0, then cannot move through 
// that element.

// Input:
// 2
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// 6
// 1 4 3 2 6 7
// Output:
// 3
// 2

// Explanation:
// Testcase 1: First jump from 1st element, and we jump to 2nd element 
// with value 3. Now, from here we jump to 5h element with value 9. 
// and from here we will jump to last.

// Time - O(n)
// Space - O(1)

// stairs and ladder method
// cannot tell the steps taken, only min number of steps taken
#include<iostream>
using namespace std;

int minJump(int arr[], int n)
{
    int i = 1;
    int count = 1;
    
    int stairs = arr[0], ladder=arr[0];
    if(stairs == 0)
        return -1;
    while(i < n)
    {
        if(i == n-1)
            break;
        
        if(i + arr[i] > ladder)
            ladder = i + arr[i];
        
        stairs--;
        if(stairs == 0)
        {
            count++;
            stairs = ladder - i;
            if(stairs == 0)
            {
                count = -1;
                break;
            }
        }
        i++;
    }
    
    return count;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	        
	   cout<<minJump(arr, n)<<endl;
	}
	return 0;
}