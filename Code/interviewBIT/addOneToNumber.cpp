// Given a non-negative number represented as an array of digits,

// add 1 to the number ( increment the number represented by the 
// digits ).

// The digits are stored such that the most significant digit is at
//  the head of the list.

// Example:

// If the vector has [1, 2, 3]

// the returned vector should be [1, 2, 4]

// as 123 + 1 = 124.

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    vector<int> ret;
    if(n == 0)
        return ret;
        
    reverse(A.begin(), A.end());
    int carry = 1;
    
    for(int i=0; i<n; i++)
    {
        int sum = A[i] + carry;
        ret.push_back(sum%10);
        carry = sum / 10;
    }
    
    while(carry)
    {
        ret.push_back(carry%10);
        carry /= 10;
    }
    
    while(ret[ret.size() - 1] == 0 && ret.size() > 1)
        ret.pop_back();
        
    reverse(ret.begin(), ret.end());
    return ret;
}