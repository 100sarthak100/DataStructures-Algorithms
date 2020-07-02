// You are given a binary string(i.e. with characters 0 and 1) S 
// consisting of characters S1, S2, …, SN. In a single operation, 
// you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and 
// flip the characters SL, SL+1, …, SR. By flipping, we mean change 
// character 0 to 1 and vice-versa.

// Your aim is to perform ATMOST one operation such that in final 
// string number of 1s is maximised. If you don’t want to perform 
// the operation, return an empty array. Else, return an array 
// consisting of two elements denoting L and R. If there are 
// multiple solutions, return the lexicographically 
// smallest pair of L and R.

// For example,

// S = 010

// Pair of [L, R] | Final string
// _______________|_____________
// [1 1]          | 110
// [1 2]          | 100
// [1 3]          | 101
// [2 2]          | 000
// [2 3]          | 001

// We see that two pairs [1, 1] and [1, 3] give same number of 1s 
// in final string. So, we return [1,

// If S = 111

// No operation can give us more than three 1s in final string. So, 
// we return empty array [].

// using kaden's algo
vector<int> Solution::flip(string A) {
    int n = A.size();
    vector<int> ret;
    if(n == 0)
        return ret;
    
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == '0')
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 0)
        return ret;
        
    int start = 0, end = 0, s = 0;    
    int count = 0, maxCount = INT_MIN;
    
    for(int i=0; i<n; i++)
    {
        if(A[i] == '1')
            count--;
        else count++;
        
        if(maxCount < count)
        {
            maxCount = count;
            start = s;
            end = i;
        }
        
        if(count < 0)
        {
            count = 0;
            s = (i + 1);
        }
    }
    
    ret.push_back(start+1);
    ret.push_back(end+1);
        
    return ret;
}