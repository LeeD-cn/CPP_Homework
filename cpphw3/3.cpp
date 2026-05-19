#include <iostream>
using namespace std;
class Car;
class Boat{
public:
    Boat(){ weight = 0;}
    Boat(double w)
    {
        weight = w;
    }
    void Set(double w)
    {
        weight = w;
    }
    void Print()
    {
        cout << "Boat's weight(kg) = " << weight << endl;
    }
    friend double TotalWeight(Boat &, Car &);
private:
    double weight;
};
class Car{
public:
    Car(double w)
    {
        weight = w;
    }
    Car(){ weight = 0;}
    void Set(double w)
    {
        weight = w;
    }
    void Print()
    {
        cout << "Car's weight(kg) =" << weight << endl;
    }
    friend double TotalWeight(Boat &, Car &);
private:
    double weight;
};
double TotalWeight(Boat &b, Car &c)
{
    return b.weight + c.weight;
}
int main()
{
    Boat b(50);
    Car c(100);
    b.Print();
    c.Print();
    cout << "总质量是:" << TotalWeight(b, c) << endl;
    b.Set(100);
    b.Print();
    return 0;
}
