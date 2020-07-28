#include <bits/stdc++.h>
using namespace std;

class complexNumber
{
    private:
    //data members
    int real;
    float img;

    public:
    complexNumber()
    {
        cout<<"Default constructor "<<endl;
    }
    complexNumber(int r, float i)
    {
        cout<<"Parameterized constructor "<<endl;
        real = r;
        img = i;
    }
    void displayData()
    {
        cout<<"Complex number is "<<endl;
        cout<<real<<" + i"<<img<<endl<<endl;
    }

    int getRealPart()
    {
        return real;
    }

    float getImgPart()
    {
        return img;
    }
};

complexNumber add2Number(complexNumber n1, complexNumber n2)
{
    int r;
    float i;
    r = n1.getRealPart() + n2.getRealPart();
    i = n1.getImgPart() + n2.getImgPart();
    complexNumber temp(r, i);
    return temp;
}

int main()
{
    complexNumber comp1(5, 4), comp2(6, 5), comp3;
    comp1.displayData();
    comp2.displayData();
    comp3 = add2Number(comp1, comp2);
    comp3.displayData();

    cout<<"pointer to object"<<endl;
    complexNumber* ptr1;
    ptr1 = &comp3;
    ptr1->displayData();

    ptr1 = &comp2;
    ptr1->displayData();

    cout<<ptr1<<endl;//address of comp2 object
}