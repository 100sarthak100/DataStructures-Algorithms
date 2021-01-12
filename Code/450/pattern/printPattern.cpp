// Print a pattern of numbers from to

// as shown below. Each of the numbers is separated by a single space.

//                             4 4 4 4 4 4 4  
//                             4 3 3 3 3 3 4   
//                             4 3 2 2 2 3 4   
//                             4 3 2 1 2 3 4   
//                             4 3 2 2 2 3 4   
//                             4 3 3 3 3 3 4   
//                             4 4 4 4 4 4 4   

// Sample Input 0

// 2

// Sample Output 0

// 2 2 2
// 2 1 2
// 2 2 2

// Sample Input 1

// 5

// Sample Output 1

// 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 2 1 2 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 4 4 4 4 4 4 5 
// 5 5 5 5 5 5 5 5 5

// Sample Input 2

// 7

// Sample Output 2

// 7 7 7 7 7 7 7 7 7 7 7 7 7 
// 7 6 6 6 6 6 6 6 6 6 6 6 7 
// 7 6 5 5 5 5 5 5 5 5 5 6 7 
// 7 6 5 4 4 4 4 4 4 4 5 6 7 
// 7 6 5 4 3 3 3 3 3 4 5 6 7 
// 7 6 5 4 3 2 2 2 3 4 5 6 7 
// 7 6 5 4 3 2 1 2 3 4 5 6 7 
// 7 6 5 4 3 2 2 2 3 4 5 6 7 
// 7 6 5 4 3 3 3 3 3 4 5 6 7 
// 7 6 5 4 4 4 4 4 4 4 5 6 7 
// 7 6 5 5 5 5 5 5 5 5 5 6 7 
// 7 6 6 6 6 6 6 6 6 6 6 6 7 
// 7 7 7 7 7 7 7 7 7 7 7 7 7 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	int len = 2*n - 1;
    int min1, min2, minVal;
    for(int i=1; i<=len; i++)
    {
        for(int j=1; j<=len; j++)
        {
            min1 = (len - i < i - 1) ? len - i : i - 1;
            min2 = (len - j < j - 1) ? len - j : j - 1;
            minVal = (min1 < min2) ? min1 : min2;
            printf("%d ", n - minVal);
        }
        printf("\n");
    }
    return 0;
}