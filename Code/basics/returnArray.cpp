#include <bits/stdc++.h>
using namespace std;

// wrong method
// int* func(int n)
// {
//     int arr[n];
//     for(int i=0; i<n; i++)
//         arr[i] = i;
//     return arr;
// }

//correct method
//using dynamically allocated array;
int* func(int n)
{
    int* arr = new int[n];
    for(int i=0; i<n; i++)
        arr[i] = i;
    return arr;
}

//correct method
//using static array;
// int* func(int n)
// {
//     //cannot have arr[n]
//     static int arr[100];
//     for(int i=0; i<n; i++)
//         arr[i] = i;
//     return arr;
// }

//correct method
//using struct
// struct arrWrap
// {
//     int arr[100];
// };

// int* func(int n)
// {
//     arrWrap x;
//     for(int i=0; i<n; i++)
//         x.arr[i] = i;
//     return x;
// }

// int main() 
// { 
//     struct arrWrap x = fun(); 
//     cout << x.arr[0] << " " << x.arr[1]; 
//     return 0; 
// } 

int main()
{
    int* arr;
    int n = 10;
    arr = func(n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}