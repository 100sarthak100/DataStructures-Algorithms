// iven an integer an N. The task is to return the position of first 
// set bit found from the right side in the binary 
// representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from 
// the function.  

// Example 1:

// Input: N = 18
// Output: 2
// Explanation: Binary representation of 18 is 010010,
// the first set bit from the right side is at position 2.
// Example 2:

// Input: N = 12 
// Output: 3 
// Explanation: Binary representation of  12 is 1100,
// the first set bit from the right side is at position 3.
// Your Task:
// The task is to complete the function getFirstSetBit() that takes 
// an integer n as a parameter and returns the position of first set 
// bit.

unsigned int getFirstSetBit(int n){
    int k = 0;
    while(k != 31)
    {
    if(n&(1<<k))
        return k+1;
    else
        k++;
    }
    return 0;
}