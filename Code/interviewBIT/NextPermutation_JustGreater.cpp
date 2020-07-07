// Implement the next permutation, which rearranges numbers into the 
// numerically next greater permutation of numbers for a 
// given array A of size N.

// If such arrangement is not possible, it must be rearranged as the 
// lowest possible order i.e., sorted in an ascending order.

// Input 1:
//     A = [1, 2, 3]

// Output 1:
//     [1, 3, 2]

// Input 2:
//     A = [3, 2, 1]

// Output 2:
//     [1, 2, 3]

// Input 3:
//     A = [1, 1, 5]

// Output 3:
//     [1, 5, 1]

// Input 4:
//     A = [20, 50, 113]

// Output 4:
//     [20, 113, 50]

// Time - O(N)
// Space - O(1)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int pivot = -1;
    for(int i=n-1; i>=0; i--)
    {
        if(A[i-1] < A[i])
        {
            pivot = i-1;
            break;
        }
    }
    
    if(pivot == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    
    for(int i=n-1; i>=0; i--)
    {
        if(A[i] > A[pivot])
        {
            swap(&A[i], &A[pivot]);
            break;
        }
    }
    reverse(A.begin()+pivot+1, A.end());
    return A;
}