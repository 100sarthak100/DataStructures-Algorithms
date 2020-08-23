// Given a binary string, that is it contains 
// only 0s and 1s. We need to make this string a 
// sequence of alternate characters by flipping some 
// of the bits, our goal is to minimize the number of 
// bits to be flipped.
// Examples:

// Input : str = “001”
// Output : 1
// Minimum number of flips required = 1
// We can flip 1st bit from 0 to 1 

// Input : str = “0001010111”
// Output : 2
// Minimum number of flips required = 2
// We can flip 2nd bit from 0 to 1 and 9th 
// bit from 1 to 0 to make alternate 
// string “0101010101”.

// Input
// 2
// 01010
// 1111

// Output
// 0
// 2

#include<iostream>
using namespace std;

char flip(char ex)
{
    return (ex == '0') ? '1' : '0';
}

int minVal(string s, char expected)
{
    int n = s.size();
    int flip_count = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] != expected)
            flip_count++;
        expected = flip(expected);
    }
    return flip_count;
}

int minFlip(string s)
{
    if(s.size() == 0)
        return 0;
    return min(minVal(s, '0'), minVal(s, '1'));
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<minFlip(s)<<endl;
	}
	return 0;
}