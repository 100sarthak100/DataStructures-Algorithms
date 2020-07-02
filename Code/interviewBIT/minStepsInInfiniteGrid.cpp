// You are in an infinite 2D grid where you can move in any of 
// the 8 directions
// You are given a sequence of points and the order in which you 
// need to cover the points.. Give the minimum number of steps in 
// which you can achieve it. 
// You start from the first point.

// Example Input
// Input 1:

//  A = [0, 1, 1]
//  B = [0, 1, 2]


// Example Output
// Output 1:

//  2

 int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if(n != m)
        return 0;
    
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        sum += max(abs(A[i] - A[i-1]), abs(B[i] - B[i-1]));
    }
    return sum;
}