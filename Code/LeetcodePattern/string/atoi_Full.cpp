// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters 
// as necessary until the first non-whitespace character is 
// found. Then, starting from this character, takes an optional 
// initial plus or minus sign followed by as many numerical digits 
// as possible, and interprets them as a numerical value.

// The string can contain additional characters after those 
// that form the integral number, which are ignored and have 
// no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str 
// is not a valid integral number, or if no such sequence exists 
// because either str is empty or it contains only whitespace 
// characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is 
// returned.

// Example 1:

// Input: "42"
// Output: 42
// Example 2:

// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', 
// which is the minus sign.
//              Then take as many numerical digits as possible,
//               which gets 42.
// Example 3:

// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character 
// is not a numerical digit.
// Example 4:

// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which 
// is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion 
//              could be performed.
// Example 5:

// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of 
// a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.

class Solution {
public:
    bool isAlpha(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        else
            return false;
    }
    
    bool isDigit(char c)
    {
        if(c >= '0' && c<='9')
            return true;
        else
            return false;
    }
    
    int myAtoi(string str) {
        int n = str.size();
        long long dec = 0;
        int sign = 1;
        long long i = 0;
        
        while(str[i] == ' ')
            i++;
        
        if(isAlpha(str[i]))
            return 0;
        
        sign = (str[i] == '-') ? -1 : 1;
        if(str[i] == '-' || str[i] == '+')
            i++;
        
        for(;i<n; i++)
        {
            if(isDigit(str[i]))
            {
                if(dec*10*sign > INT_MAX)
                    return INT_MAX;
                else if(dec*10*sign < INT_MIN)
                    return INT_MIN;
                
                dec = dec*10 + (str[i] - '0');
            }  
            else
                break;
        }
        
        if(dec*sign > INT_MAX)
            return INT_MAX;
        else if(dec*sign < INT_MIN)
            return INT_MIN;
        return dec*sign;
        
    }
};