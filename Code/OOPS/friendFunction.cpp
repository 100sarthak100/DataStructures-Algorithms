#include <bits/stdc++.h>
using namespace std;

class Distance
{
    private:
    int meters;

    public:
    Distance()
    {
        cout<<"Default constructor"<<endl;
        meters = 0;
    }
    void displayData()
    {
        cout<<"Meters value "<<meters<<endl;
    }
    //prototype of friend function
    friend void addValue(Distance &d);

    int getVal()
    {
        return meters;
    }
};

//can change the value
void addValue(Distance &d)
{
    d.meters = d.meters + 5;
}

// only will print the meters value can'y change it
void addval(Distance &d)
{
    cout<<d.getVal()<<endl;
}

int main()
{
    Distance d1;
    d1.displayData();
    //friend function call
    addValue(d1);//pass by reference
    d1.displayData();

    addval(d1);
}