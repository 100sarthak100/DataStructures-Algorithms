// transpose inplace for square matrix

void transpose(int A[][N]) 
{ 
    for (int i = 0; i < N; i++) 
        for (int j = i; j < N; j++) 
            swap(A[i][j], A[j][i]); 
} 

// recatngular matrix
void transpose(int A[][N], int B[][M]) 
{ 
    int i, j; 
    for (i = 0; i < N; i++) 
        for (j = 0; j < M; j++) 
            B[i][j] = A[j][i]; 
} 

// for square matrix
void transpose(int A[][N], int B[][N]) 
{ 
    int i, j; 
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++) 
            B[i][j] = A[j][i]; 
} 