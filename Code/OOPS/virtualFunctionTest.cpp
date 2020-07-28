#include <bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    virtual void move()
    {
        cout<<"Animal move "<<endl;
    }
};

class Dog : public Animal
{
    public:
    void move()
    {
        cout<<"Dog walks "<<endl;
    }
};

class Birds : public Animal
{
    public:
    void move()
    {
        cout<<"Birds fly "<<endl;
    }
};

void mobility(Animal* a)
{
    a->move();
}

// void mobility(Dog* a)
// {
//     a->move();
// }

// void mobility(Birds* a)
// {
//     a->move();
// }

int main()
{
    Animal* ptr;
    
    Dog d1;
    Birds b1;

    ptr = &d1;
    mobility(ptr);

    ptr = &b1;
    mobility(ptr);

    // have to make 2 function without virtual function
    // Dog* ptrD;
    // mobility(ptrD);

    // Birds* ptrB;
    // mobility(ptrB);
}