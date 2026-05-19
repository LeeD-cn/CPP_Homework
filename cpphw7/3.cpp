#include <iostream>
#include <cmath>
using namespace std;
class Triangle;
class Point {
 public:
    Point(int x = 0, int y = 0) 
    {
        X = x, Y = y;
        cout << "constuct Point(" << X << "," << Y << ")\n";
    }
    Point(const Point& other_Point)
    {
        X = other_Point.X, Y = other_Point.Y;
        cout << "copy constuct Point(" << X << "," << Y << ")\n";
    }
    ~Point()
    {
        cout << "destroy Point(" << X << "," << Y << ")\n";
    }
    void Set(int x, int y);
    void Print() const;
    int get_X() const
    {
        return X;
    }
    int get_Y() const
    {
        return Y;
    }
 protected:
    int X, Y;
};
void Point::Set(int x, int y)
{
    X = x, Y = y;
} 
void Point::Print() const
{
    cout << "(" << X << "," << Y << ")\n";
}
class Triangle : public Point {
 public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : p1(x1, y1), p2(x2, y2), Point(x3, y3)
    {
        cout << "construct triangle\n";
    }
    Triangle(const Triangle& other_Triangle)
    : p1(other_Triangle.p1), p2(other_Triangle.p2), Point(other_Triangle)
    {
        cout << "copy construct triangle\n";
    }
    ~Triangle()
    {
        cout << "destroy Triangle\n";
    }
    void Set(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        Point::Set(x3, y3);
        p1.Set(x1, y1), p2.Set(x2, y2);
    }
    void Print() const;
    double Area() const;
 protected:
    Point p1, p2;
};
void Triangle::Print() const
{
    p1.Print(), p2.Print(), Point::Print();
}
double Triangle::Area() const
{
    double area = (p1.get_X() - Point::X) * (p2.get_Y() - Point::Y) - (p2.get_X() - Point::X) * (p1.get_Y() - Point::Y);
    return (abs(area) / 2);
}
int main()
{
    Triangle t1(0, 0, 1, 0, 0, 1), t2(t1);
    t1.Print();
    t2.Print();
    t2.Set(0, 1, 2, 3, 0, 5);
    t2.Print();
    cout << t1.Area() << endl;
    cout << t2.Area() << endl;
    return 0;
}