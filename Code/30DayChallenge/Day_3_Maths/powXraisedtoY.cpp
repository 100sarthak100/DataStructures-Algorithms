// output - 0.125000

// works for negative as well positive powers.

// Algorithmic Paradigm: Divide and conquer.
// time - O(logn)
// space - O(1)

// recursive (requires space on call stack)
#include <bits/stdc++.h>
using namespace std;

float power(int x, int y)
{
    if(y == 0)
        return 1;
    
    float temp = power(x, y/2);

    if(y % 2 == 0)
        return temp * temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp)/x;
    }
}

int main()
{
    int x = 2;
    int y = -3;
    cout<<power(x, y)<<endl;
}

// same solution but faster
class Solution {
public:
    double power(double x,int n){
        if(n==0) return 1;
        double temp = power(x,n/2);
        temp = temp*temp;
        if(n&1)
            temp = temp*x;
        return temp;
    }
    double myPow(double x, int n) {
        double result = power(abs(x),abs(n));
        
        // 2^2 = 4, 2^-2 == 0.25 == 1/4 == 1/(2^2)
        if(n<0){
         result = 1.0/result*1.0;
        }
        // 2^3 == 8 , -2^3 = -8 (n&1 == 0 , if n is even)
        if(x<0 && n&1) {
            result=result*-1;
        }
        // if x < 0 and n is even then result is positive
        return result;
    }
};