#include <iostream>
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
class Circle : public Point {
 public:
    Circle(int X, int Y, double r)
    : Point(X, Y), R(r) {}
    Circle(const Circle& other_Circle)
    : Point(other_Circle), R(other_Circle.R) {}
    ~Circle()
    {
        cout << "destroy Circle\n";
    }
    double GetArea() const;
    double GetR() const
    {
        return R;
    }
 private:
    double R;
};
double Circle::GetArea() const
{
    return PI * R * R;
}
class Rectangle : public Point {
 public:
    Rectangle(int X, int Y, double height, double width)
    : Point(X, Y), Height(height), Width(width) {}
    Rectangle(const Rectangle& other_Rectangle)
    : Point(other_Rectangle), Height(other_Rectangle.Height), Width(other_Rectangle.Width) {}
    ~Rectangle()
    {
        cout << "destroy Rectangle\n";
    }
    double GetWidth() const
    {
        return Width;
    }
    double GetHeight() const
    {
        return Height;
    }
    double GetArea() const
    {
        return Height * Width;
    }
 protected:
    double Height, Width;
};
class Square : public Rectangle {
 public:
    Square(int X, int Y, double side)
    : Rectangle(X, Y, side, side), Side(Height) {}
    Square(const Square& other_Square)
    : Rectangle(other_Square), Side(Height) {}
    ~Square()
    {
        cout << "destroy Square\n";
    }
    double GetArea() const
    {
        return Side * Side;
    }
    double GetSide() const
    {
        return Side;
    }
 private:
    double Side;
};
void PrintArea(const Point *a)
{
    cout << "The area is " << a->GetArea() << endl;
}
int main()
{
    Point *shape[] = {new Circle(0, 0, 1), new Rectangle(1, 1, 3, 4), new Square(3, 3, 5)};
    for(int i = 0; i < 3; i++)
    {
        PrintArea(shape[i]);
        delete shape[i];
    }
    return 0;
}