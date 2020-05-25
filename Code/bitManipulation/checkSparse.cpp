// Testcase 1: Binary Representation of 2 is 10, which is not having consecutive set bits. So, it is sparse number.
// Testcase 2: Binary Representation of 3 is 11, which is having consecutive set bits in it. So, it is not a sparse number.


bool isSparse(int n){
    
    return (n&(n<<1)) == 0;
    
}