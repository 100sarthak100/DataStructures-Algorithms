#include <bits/stdc++.h>
using namespace std;

// user defined data type
class Cars
{
    private:
    //memeber variables or data memebers
    string company_name;
    string model_name;
    string fuel_type;
    float mileage;
    double price;

    public:

    Cars()
    {
        cout<<"Default constructor called"<<endl;
        company_name = "Toyota";
    }
    //parameterized constructor
    Cars(string cname, string mname, string ftype, float m, float p)
    {
        cout<<"Parametrized constructor is called "<<endl;
        company_name = cname;
        model_name = mname;
        fuel_type = ftype;
        mileage = m;
        price = p;
    }
    //copy constructor
    Cars(Cars &obj)
    {
        cout<<"Copy constructor is called "<<endl;
        company_name = obj.company_name;
        model_name = obj.model_name;
        fuel_type = obj.fuel_type;
        mileage = obj.mileage;
        price = obj.price;
    }

    //member functions
    void setData(string cname, string mname, string ftype, float m, float p)
    {
        cout<<"member function setData is called "<<endl;
        company_name = cname;
        model_name = mname;
        fuel_type = ftype;
        mileage = m;
        price = p;
    }

    void displayData()
    {
        cout<<"Car properties :"<<endl;
        cout<<"Company name :"<<company_name<<endl;
        cout<<"Car model :"<<model_name<<endl;
        cout<<"fuel type :"<<fuel_type<<endl;
        cout<<"Milaege :"<<mileage<<endl;
        cout<<"Pricee :"<<price<<endl<<endl;
    }

    //destructor
    ~Cars()
    {
        cout<<"Destructor is called "<<endl;
    }
};

int main()
{
    Cars car1; //objects are variables of type class;
    car1.setData("Toyota","Altis","Petrol",15.5,150000);
    car1.displayData();
    Cars car2("Fortuner","xyz","Diesel",14.5,130000);
    car2.displayData();

    Cars car3 = car1;//copy constructor
    car3.displayData();
}