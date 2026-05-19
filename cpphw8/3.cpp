#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;
class Point {
 public:
    Point(int X = 0, int Y = 0)
    {
        x = X, y = Y;
    }
    Point(const Point& other_Point)
    {
        x = other_Point.x, y = other_Point.y;
    }
    virtual ~Point()
    {
        cout << "destroy Point\n";
    }
    virtual double GetArea() const = 0;
    int Getx() const;
    int Gety() const;
 private:
    int x, y;
};
int Point::Getx() const
{
    return x;
}
int Point::Gety() const
{
    return y;
}
class Circle : virtual public Point {
 public:
    Circle(int X, int Y, double r)
    : Point(X, Y), R(r) {}
    Circle(const Circle& other_Circle)
    : Point(other_Circle), R(other_Circle.R) {}
    ~Circle()
    {
        cout << "destroy Circle\n";
    }
    double GetArea() const
    {
        return PI * R * R;
    }
    double GetR() const
    {
        return R;
    }
 private:
    double R;
};
class Square : virtual public Point {
 public:
    Square(int X, int Y, double l)
    : Point(X, Y), L(l) {}
    Square(const Square& other_Square)
    : Point(other_Square), L(other_Square.L) {}
    ~Square()
    {
        cout << "destroy Square\n";
    }
    double GetArea() const
    {
        return L * L;
    }
    double GetL() const
    {
        return L;
    }
 private:
    double L;
};
class Margin : public Circle, public Square {
 public:
    Margin(int X, int Y, double r, double l)
    : Point(X, Y), Circle(0, 0, r), Square(0, 0, l) {}
    Margin(const Margin& other_Margin)
    : Point(other_Margin), Circle(other_Margin), Square(other_Margin) {}
    ~Margin()
    {
        cout << "destroy Margin\n";
    }
    double GetArea() const
    {
        bool judger = (GetL() >= sqrt(2) * GetR() && GetL() <= 2 * GetR());
        return (judger) ? -1 : abs(Circle::GetArea() - Square::GetArea());
    }
};
int main()
{
    Margin margin1(2, 3, 1, 9), margin2(0, 0, 10, 2);
    cout << "margin1's area = " << margin1.GetArea() << endl;
    cout << "margin2's area = " << margin2.GetArea() << endl;
    return 0;
}