// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, 
// set its entire row and column to 0.

// Note: This will be evaluated on the extra memory used. Try to 
// minimize the space and time complexity.

// Input 1:
//     [   [1, 0, 1],
//         [1, 1, 1], 
//         [1, 1, 1]   ]

// Output 1:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [1, 0, 1]   ]

// Input 2:
//     [   [1, 0, 1],
//         [1, 1, 1],
//         [1, 0, 1]   ]

// Output 2:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [0, 0, 0]   ]

// best solution
// time - O(N*M)
// space - O(1)
void Solution::setZeroes(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n==0 || m == 0)
        return;
    
    bool firstRowZero = false, firstColZero = false;
    
    for(int i=0; i<n; i++)
    {
        if(A[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }
            
    for(int i=0; i<m; i++)
    {
        if(A[0][i] == 0)
        {
            firstRowZero = true;
            break;
        }
    }
            
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(A[i][j] == 0)
            {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }
    
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(A[i][0] == 0 || A[0][j] == 0)
                A[i][j] = 0;
        }
    }
    
    if(firstRowZero)
    {
        for(int i=0; i<m; i++)
            A[0][i] = 0;
    }
    
    if(firstColZero)
    {
        for(int i=0; i<n; i++)
            A[i][0] = 0;
    }
    
    return;
}
