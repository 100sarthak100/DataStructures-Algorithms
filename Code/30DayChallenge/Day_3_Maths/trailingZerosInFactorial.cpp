// Given an integer n, write a function that returns count of 
// trailing zeroes in n!.

// Input: n = 5
// Output: 1 
// Factorial of 5 is 120 which has one trailing 0.

// Input: n = 20
// Output: 4
// Factorial of 20 is 2432902008176640000 which has
// 4 trailing zeroes.

// Input: n = 100
// Output: 24

// Example:
// Input:
// 1
// 9
// Output:
// 1

//  A trailing zero is always produced by prime factors 2 and 5. 
//  If we can count the number 
//  of 5s and 2s, our task is done.

//  Trailing 0s in n! = Count of 5s in prime factors of n!
//                   = floor(n/5) + floor(n/25) + floor(n/125) + ....

#include<iostream>
using namespace std;

int trailingCount(int n)
{
    if(n == 0)
        return 0;
    
    int count = 0;
    for(int i=5; n/i >=1; i *= 5)
    {
        count += n/i;
    }
    return count;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<trailingCount(n)<<endl;
	}
	return 0;
}