// without changing the array
int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() == 0)
        return 0;
    int slow = A[0];
    int fast = A[0];
    do
    {
        slow = A[slow];
        fast = A[A[fast]];
    }while(slow != fast);
    
    fast = 0;
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}