#include <bits/stdc++.h>
using namespace std;

void fun(int a)
{
    a = 127;
    return;
}

void fun2(int* a)
{
    *a = 127;
    return;
}

void fun3(int &a)
{
    a = 227;
    return;
}

int main()
{
    int a = 10;
    int* ptr = &a;
    int &ref = a;
    cout<<ptr<<" "<<&ptr<<" "<<*ptr<<" "<<&a<<endl;
    cout<<&ref<<" "<<ref<<endl;

    int b = 15;
    ref = b;
    cout<<&ref<<" "<<ref<<endl;

    ptr = &b;
    cout<<ptr<<" "<<&ptr<<" "<<*ptr<<" "<<&a<<" "<<&b<<endl;

    fun(a);
    cout<<a<<endl;

    fun2(&a);
    cout<<a<<endl;

    fun3(a);
    cout<<a<<endl;
}