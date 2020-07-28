#include <bits/stdc++.h>
using namespace std;

int main()
{
    int* ptr;
    int x;
    ptr = &x;
    *ptr = 0;
    cout<<ptr<<" "<<*ptr<<" "<<x<<endl;

    *ptr += 5;
    cout<<ptr<<" "<<*ptr<<" "<<x<<endl;

    (*ptr)++;
    cout<<ptr<<" "<<*ptr<<" "<<x<<endl;

    int* ptr2;
    //adding to address
    ptr2 = ptr + 5;
    //adding to value
    *ptr2 = *ptr + 5;
    cout<<ptr<<" "<<*ptr<<" "<<ptr2<<" "<<*ptr2<<endl;

}