// You are given a set of n types of rectangular 3-D boxes, where the i^th box has 
// height h(i),width w(i) and depth d(i)
// You want to create a stack of boxes which is as tall as possible, but you can 
// only stack a box on top of another box if the dimensions of the 2-D base of the 
// lower box are each strictly larger than those of the 2-D base of the higher box
// can rotate the box

// 10 x 12 x 32
//    12 x 10 x 32
//    32 x 10 x 12
//    4 x 6 x 7
//    4 x 5 x 6
//    6 x 4 x 7
//    5 x 4 x 6
//    7 x 4 x 6
//    6 x 4 x 5
//    1 x 2 x 3
//    2 x 1 x 3
//    3 x 1 x 2

// The height 60 is obtained by boxes { {3, 1, 2}, {1, 2, 3}, {6, 4, 5}, 
// {4, 5, 6}, {4, 6, 7}, {32, 10, 12}, {10, 12, 32}}

// Time Complexity: O(n^2)
// Auxiliary Space: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Box
{
    int h, w, d;
};

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int compare(const void *a, const void *b)
{
    return ( (*(Box *)b).d * (*(Box *)b).w) - 
           ( (*(Box *)a).d * (*(Box *)a).w);
}

int maxStackHeight(Box arr[], int n)
{
    Box rot[3*n];
    int index = 0;
    // rotate the boxes 3 times
    for(int i = 0; i<n; i++)
    {
        rot[index].h = arr[i].h;
        rot[index].d = max(arr[i].d, arr[i].w);
        rot[index].w = min(arr[i].d, arr[i].w);
        index++;

        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].h, arr[i].d);
        rot[index].w = min(arr[i].h, arr[i].d);
        index++;

        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].w, arr[i].h);
        rot[index].w = min(arr[i].w, arr[i].h);
        index++;
    }

    n = 3*n;

    qsort(rot, n, sizeof(rot[0]), compare);

    // print all the boxes dim in non increasing order
    for(int i = 0; i<n; i++)
        cout<<rot[i].h<<" "<<rot[i].w<<" "<<rot[i].d<<endl;

    // creating an array of maximum stack height
    int msh[n];
    for(int i = 0; i<n; i++)
        msh[i] = rot[i].h;
    
    // creating an array to store the indexes of box
    int boxStack[n];
    for(int i = 0; i<n; i++)
        boxStack[i] = -1;

    // main for loop
    for(int i = 1; i<n; i++)
        for(int j = 0; j <i; j++)
        if(rot[i].w < rot[j].w &&
            rot[i].d < rot[j].d &&
            msh[i] < msh[j] + rot[i].h)
        {
            msh[i] = msh[j] + rot[i].h;
            boxStack[i] = j;
        }

    // to find the index with max value in msh , and also to print boxStack array
    int maxEle = -1, maxIndex = 0;
    for(int i = 0;i<n;i++)
    {
        //cout<<boxStack[i]<<" ";
        if(boxStack[i] > maxEle)
        {
            maxEle = boxStack[i];
            maxIndex = i;
        }
    }
    cout<<endl;

    // to print the stack which led to the max stack height
    int a = maxIndex;
    while(a >= 0)
    {
        cout<<"{"<<rot[a].h<<" "<<rot[a].w<<" "<<rot[a].d<<"}"<<endl;
        a = boxStack[a];
    }

    // to find the max height in msh array
    int max = -1;
    for(int i = 0; i<n; i++)
        if(max < msh[i])
            max = msh[i];
    
    return max;
}

int main()
{
    // array of type box
    Box arr[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The maximum possible height of stack is %d\n",
           maxStackHeight(arr, n));
    return 0;
}


// if input is in different arrays

// struct Box
// {
//     int h, w, l;
// };

// int compare(const void *a, const void *b)
// {
//     return ( (*(Box *)b).l * (*(Box *)b).w) - 
//            ( (*(Box *)a).l * (*(Box *)a).w);
// }

// int maxHeight(int height[],int width[],int length[],int n)
// {
//     Box rot[3*n];
//     int index = 0;
//     for(int i = 0;i<n; i++)
//     {
//         rot[index].h = height[i];
//         rot[index].w = max(width[i], length[i]);
//         rot[index].l = min(width[i], length[i]);
//         index++;
        
//         rot[index].h = width[i];
//         rot[index].w = max(height[i], length[i]);
//         rot[index].l = min(height[i], length[i]);
//         index++;
        
//         rot[index].h = length[i];
//         rot[index].w = max(width[i], height[i]);
//         rot[index].l = min(width[i], height[i]);
//         index++;
//     }
    
//     n = 3*n;
//     qsort(rot, n, sizeof(rot[0]), compare);
    
//     int msh[n];
//     for(int i = 0;i<n;i++)
//         msh[i] = rot[i].h;
        
//     for(int i = 1; i<n;i++)
//     {
//         for(int j = 0; j<i;j++)
//         {
//             if(rot[i].w < rot[j].w &&
//                 rot[i].l < rot[j].l && msh[i] < msh[j] + rot[i].h)
//             {
//                 msh[i] = msh[j] + rot[i].h;
//             }
//         }
//     }
//     // for(int i = 0;i<n;i++)
//     //     cout<<msh[i]<<" ";
    
//     return *max_element(msh, msh+n);
// }