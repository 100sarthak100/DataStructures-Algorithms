// Given N number of square blocks. The height of each square block 
// is 1. The task is to create a  staircase of max height using these 
// blocks.Note: The first stair would require only one block, the
// second stair would require two blocks and so on.

// Input:
// 3
// 10
// 12
// 16
// Output:
// 4
// 4
// 5

// Explanation:
// Test Case 1: the max height of the staircase that can be made 
// from  12  blocks is 4. (A staircase of height 4 means 
// sequence of 1,2,3,4 blocks to create a valid staircase.)

#include<iostream>
using namespace std;

long long int stair(int n)
{
    if(n == 0 || n == 1)
        return n;
    int i = 1;
    while(i*(i+1)/2 <= n)
    {
        i++;
    }
    return i-1;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<stair(n)<<endl;
	}
	return 0;
}
