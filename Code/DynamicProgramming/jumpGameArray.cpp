// Input 1:
//     A = [2,3,1,1,4]
// Output 1:
//     1
// Explanation 1:
//     Index 0 -> Index 2 -> Index 3 -> Index 4 -> Index 5
// Input 2:
//     A = [3,2,1,0,4]
// Output 2:
//     0
// Explanation 2:
//     There is no possible path to reach the last index.

// Determine if you are able to reach the last index.
int Solution::canJump(vector<int> &A)
{
    int myPower = A[0];
    for (int i = 1; i < A.size(); ++i)
    {
        if (myPower == 0)
            return 0;
        myPower--;
        myPower = max(A[i], myPower);
    }
    return 1;
}