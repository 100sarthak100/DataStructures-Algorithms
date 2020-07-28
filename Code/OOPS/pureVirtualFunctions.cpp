#include <bits/stdc++.h>
using namespace std;

class shape
{
    public:
    //pure virtual function
    virtual void getArea()=0;
};

// class is an abstract if it has atleast 1 pure
// virtual function

class Circle : public shape
{
    public:
    void getArea()
    {
        cout<<"Enter circle radius"<<endl;
        int r;cin>>r;
        cout<<"Area of circle is: "<<(3.14*r*r)<<endl;
    }
};

int main()
{
    Circle c1;
    c1.getArea();
}