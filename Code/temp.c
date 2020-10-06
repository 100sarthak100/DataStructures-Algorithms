// // #include "stdio.h"


// // int main()
// // {

// // int i = 5;
// // printf("%d\n", i++ * i--);

// // return 0;
// // }

// /*
// why do you want to join this company :
// I am a quick learner. Throughout my time in college i have kept myself engaged 
// in learning new skills and making projects. I can work in a fast paced 
// environment. working in a Invest banking firm requires great deal of problem
// solving and i think that i have the ability to do so. 
// */

// #include <stdio.h>

// int main()
// {
//     int *ptr1, *ptr2;
//     ptr1 = malloc(4);
//     *ptr1 = 10;
//     *ptr2 = free(ptr1);
//     printf("%d\n", *ptr2);
//     return 0;
// }

#include <stdio.h>
#define defMethod(i)(i*i)
void main()
{
    int a, b=5;
    a = defMethod(b+5);
    printf("\n%d",a);
}