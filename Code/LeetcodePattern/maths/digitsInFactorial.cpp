// Given an integer N. The task is to find the number of digits 
// that appear in its factorial, where factorial is defined as, 
// factorial(n) = 1*2*3*4……..*N and factorial(0) = 1.

// Example 1:

// Input:
// N = 5
// Output: 3
// Explanation: Factorial of 5 is 120.
// Number of digits in 120 is 3 (1, 2, and 0)
// Example 2:

// Input:
// N = 120
// Output: 199
// Explanation: The number of digits in
// 200! is 199

// We know,
// log(a*b) = log(a) + log(b)

// Therefore
// log( n! ) = log(1*2*3....... * n) 
//           = log(1) + log(2) + ........ +log(n)

// Now, observe that the floor value of log base 
// 10 increased by 1, of any number, gives the
// number of digits present in that number.

// Hence, output would be : floor(log(n!)) + 1.

int digitsInFactorial(int N)
{
    if(N < 0)
        return 0;
    if(N <= 1)
        return 1;
        
    double digits = 0;
    for(int i=2; i<=N; i++)
        digits += log10(i);
    
    return floor(digits)+1;
}