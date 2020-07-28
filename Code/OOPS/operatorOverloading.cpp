#include <bits/stdc++.h>
using namespace std;

// class Complex
// {
//     private:
//     int real;
//     int img;

//     public:
//     Complex()
//     {
//         real = 0;
//         img = 0;
//     }

//     Complex(int r, int i)
//     {
//         real = r;
//         img = i;
//     }

//     void print()
//     {
//         cout<<real<<" + i"<<img<<endl;
//     }
//     // operator overloading
//     Complex operator +(Complex c)
//     {
//         Complex temp;
//         temp.real = real + c.real;
//         temp.img = img + c.img;
//         return temp;
//     }
// };

// int main()
// {
//     Complex c1(2, 3), c2(5, 4), c3, c4;
//     c1.print();
//     c2.print();
//     c3 = c1 + c2;// c1.add(c2)
//     cout<<"Value of c3 = ";
//     c3.print();
//     c4 = c1 + c2 + c3;
//     c4.print();

//     cout<<endl;

//     int x = 5;
//     int y = 4;
//     int z = x + y;
//     cout<<"Value of z = "<<z<<endl;
// }

class Weight
{
    private:
    int kg;

    public:
    Weight()
    {
        kg = 0;
    }

    Weight(int x)
    {
        kg = x;
    }

    void printWeight()
    {
        cout<<"Weight is: "<<kg<<endl;
    }
    //preincrement
    // void operator ++()
    // {
    //     ++kg;
    // }
    //postincrement
    void operator ++(int)
    {
        kg++;
    }
    void operator --()
    {
        --kg;
    }
    void operator --(int)
    {
        kg--;
    }

    Weight operator ++()
    {
        Weight temp;
        temp.kg = ++kg;
        return temp;
    }
};

int main()
{
    Weight obj;
    obj.printWeight();
    ++obj;
    obj.printWeight();
    obj++;
    obj.printWeight();

    --obj;
    obj.printWeight();
    obj--;
    obj.printWeight();

    Weight obj1, obj2;
    obj2 = ++obj1;
    obj2.printWeight();
}