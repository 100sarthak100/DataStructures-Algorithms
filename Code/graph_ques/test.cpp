#include <iostream>
using namespace std;

const double pi = 3.14159;

void calculate()
{
    double area;
    double radius;

    cout << "Enter Radius: " << endl;
    cin >> radius;
    system("pause");

    area = pi * radius * radius;

    cout << "area is: " << area << endl;
}

int main()
{
    calculate();
    return 0;
}
