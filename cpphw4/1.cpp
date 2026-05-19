#include <iostream>
using namespace std;
class Point{
 public:
    Point(double x = 0, double y = 0)
    :  X(x), Y(y){}
    Point(const Point& other_Point)
    {
        X = other_Point.X;
        Y = other_Point.Y;
    }
    ~Point()
    {
        cout << "析构Point(" << X << ',' << Y << ")\n";
    }
    void Set(double x, double y)
    {
        X = x;
        Y = y;
    }
    void Print() const
    {
        cout << '(' << X << ',' << Y << ')' << endl;
    }
    double Get_X() const
    {
        return X;
    }
    double Get_Y() const
    {
        return Y;
    }
 private:
    double X, Y;
};
class Rectangle{
 public:
    Rectangle(double x1 = 0, double y1 = 0, double x2 = 1, double y2 = 1)
    : left(x1, y1), right(x2, y2){}
    Rectangle(const Point& l, const Point& r)
    : left(l), right(r){}
    Rectangle(const Rectangle& other_Rectangle)
    {
        left = other_Rectangle.left;
        right = other_Rectangle.right;
    }
    ~Rectangle()
    {
        cout << "析构Rectangle" << endl;
    }
    void Set(double x1, double y1, double x2, double y2)
    {
        left.Set(x1, y1);
        right.Set(x2, y2);
    }
    void Print() const
    {
        cout << "左下角点:";
        left.Print();
        cout << "右下角点:";
        right.Print();
    }
    double Area() const;
    bool issquare() const;
    double get_x_length() const;
    double get_y_length() const;
    void translate(double x, double y);
 private:
    Point left, right;
};
double Rectangle::Area() const
{
    double area = get_x_length() * get_y_length();
    return area;
}
double Rectangle::get_x_length() const
{
    double length = right.Get_X() - left.Get_X();
    return length;
}
double Rectangle::get_y_length() const
{
    double length = right.Get_Y() - left.Get_Y();
    return length;
}
bool Rectangle::issquare() const
{
    bool result(false);
    if(get_x_length() == get_y_length()) result = true;
    return result;
}
void Rectangle::translate(double x, double y)
{
    double x1 = left.Get_X() + x;
    double y1 = left.Get_Y() + y;
    double x2 = right.Get_X() + x;
    double y2 = right.Get_Y() + y;
    left.Set(x1, y1);
    right.Set(x2, y2);
}
int main()
{
    Rectangle a(0, 1, 3, 4);
    Rectangle b(a);
    Point p1(0, 0), p2(2, 2);
    Rectangle c(p1, p2);
    if(c.issquare()) cout << "c为正方形" << endl;
    cout << "print a:" << endl;
    a.Print();
    cout << "print b:" << endl;
    b.Print();
    cout << "b's area = " << b.Area() << endl;
    c.translate(1, 2);
    cout << "after being translated c:\n";
    c.Print();
    return 0;
}