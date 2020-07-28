// function overiding

#include <bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    void makeSound()
    {
        cout<<"Animal sound"<<endl;
    }
};

class Dog: public Animal
{
    public:
    void makeSound()
    {
        cout<<"Dogs Bark"<<endl;
    }
};

class Cat: public Animal
{
    public:
    void makeSound()
    {
        cout<<"Cats Meow"<<endl;
    }
};

//function overloading
void add(int a, int b)
{
    cout<<"func 1"<<endl;
    cout<<(a + b)<<endl;
}

void add(double a, double b)
{
    cout<<"func 2"<<endl;
    cout<<(a + b)<<endl;
}

void add(int a, int b, int c)
{
    cout<<"func 3"<<endl;
    cout<<(a + b + c)<<endl;
}

void add (int a, double b)
{
    cout<<"func 4"<<endl;
    cout<<(a + b)<<endl;
}

void add (double a, int b)
{
    cout<<"func 5"<<endl;
    cout<<(a + b)<<endl;
}

int main()
{
    //function overriding
    Animal a1;
    a1.makeSound();
    Dog d1;
    d1.makeSound();
    Cat c1;
    c1.makeSound();

    //function overloading
    add(2,3,4);
    add(2.3, 4);
    add(4, 5.6);
    add(2.3,3.4,4.5);
}

