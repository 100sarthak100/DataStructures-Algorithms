// Syntax
// class derived-class:access-specifier base-class
// {

// }
// types of inheritance
// 1. single level
// 2. multi level
// 3. multiple
// 4. hierarchial
// 5. hybrid

#include <bits/stdc++.h>
using namespace std;

class shape
{
    protected:
    int width;
    int height;

    public:
    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }
};

class rectangle: public shape
{
    public:
    int getArea()
    {
        return (width * height);
    }
};

int main()
{
    rectangle rect;
    rect.setWidth(1);
    rect.setHeight(3);
    cout<<rect.getArea()<<endl;
}