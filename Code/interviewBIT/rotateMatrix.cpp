// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// You need to do this in place.

// Note that if you end up using an additional array, you will 
// only receive partial score.

// Example:

// If the array is

// [
//     [1, 2],
//     [3, 4]
// ]
// Then the rotated array becomes:

// [
//     [3, 1],
//     [4, 2]
// ]

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0; i<n; i++)
        for(int j=i; j<m; j++)
            swap(&A[i][j], &A[j][i]);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0, k=m-1; j<k; j++,k--)
            swap(&A[i][j], &A[i][k]);
    }
    return;
}