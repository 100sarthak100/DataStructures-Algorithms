// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
// The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the 
// first 11 ugly numbers. By convention, 1 is included. 
// Write a program to find Nth Ugly Number.

// Time Complexity: O(n)
// Auxiliary Space: O(n)

// Input:
// 2
// 10
// 4
// Output:
// 12
// 4

#include<iostream>
using namespace std;

unsigned long long uglyNum(unsigned long long n)
{
    if(n == 1)
        return 1;
    
    unsigned long long ugly[n];
    unsigned long long i2 = 0, i3 = 0, i5 = 0;
    unsigned long long mulTwo = 2;
    unsigned long long mulThree = 3;
    unsigned long long mulFive = 5;
    ugly[0] = 1;
    unsigned long long minVal = 1;
    
    int i = 1;
    while(i < n)
    {
        minVal = min(mulTwo, min(mulThree, mulFive));
        ugly[i] = minVal;
        if(mulTwo == minVal)
        {
            i2++;
             mulTwo = ugly[i2]*2;
        }
        if(mulThree == minVal)
        {
            i3++;
             mulThree = ugly[i3]*3;
        }
        if(mulFive == minVal)
        {
            i5++;
            mulFive = ugly[i5]*5;
        }
        i++;
    }
    return ugly[n-1];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<uglyNum(n)<<endl;
	}
	return 0;
}