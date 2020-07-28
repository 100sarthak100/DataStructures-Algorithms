#include <bits/stdc++.h>
using namespace std;

// class myBase
// {
//     public:
//     void show()
//     {
//         cout<<"base class show function called"<<endl;
//     }

//     virtual void print()
//     {
//         cout<<"base class print function called"<<endl;
//     }
// };

// class myDerived : public myBase
// {
//     public:
//     void show()
//     {
//         cout<<"Derived class show function called"<<endl;
//     }

//     void print()
//     {
//         cout<<"Derived class print function called"<<endl;
//     }
// };

// int main()
// {
//     //using the same base class pointer i can point to multiple derived class
//     // using virtual function
//     myBase* baseptr;
//     myDerived derivedObj;

//     baseptr = &derivedObj;
//     // this function linking happened dynamically during runtime
//     baseptr->print();
//     baseptr->show();
// }

class Animal
{
    public:
    void food()
    {
        cout<<"Eat generic food"<<endl;
    }
};

class Dog : public Animal
{
    public:
    void food()
    {
        cout<<"Eat Dog food"<<endl;
    }
};

class Cat : public Animal
{
    public:
    void food()
    {
        cout<<"Eat Cat food"<<endl;
    }
};

void foodPrint(Animal *d)
{
    d->food();
}

// it will work but for all derived classes will have to
// make individual functions for each
// can't do it with animal obj as a paremeter without virtual functions
// void fp(Dog &d1)
// {
//     d1.food();
// }

int main()
{
    Animal* baseptr;

    Dog objDog;
    Cat objCat;

    baseptr = &objDog;
    foodPrint(baseptr);

    baseptr = &objCat;
    foodPrint(baseptr);

    // can do like this also
    // Dog d1;
    // fp(d1);
    // d1.food();
}