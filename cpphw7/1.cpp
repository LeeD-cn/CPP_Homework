#include <iostream>
using namespace std;
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
 protected:
    int get_X() const
    {
        return X;
    }
    int get_Y() const
    {
        return Y;
    }
 private:
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
class Line : public Point {
 public:
    Line(int x, int y, double s = 0)
    : S(s), Point(x, y)
    {
        cout << "construct Line" << endl;
    }
    Line(const Line& other_Line)
    : S(other_Line.S), Point(other_Line.get_X(), other_Line.get_Y())
    {
        cout << "copy construct Line" << endl;
    }
    ~Line()
    {
        cout << "destroy Line" << endl;
    }
    void Set(int x, int y, double s)
    {
        Point::Set(x, y);
        S = s;
    }
    void Print() const;
    double get_S() const
    {
        return S;
    }
    friend bool operator||(const Line& l1, const Line& l2);
    friend bool operator==(const Line& l1, const Line& l2);
 private:
    double S;
};
void Line::Print() const
{
    cout << "过点:";
    Point::Print();
    cout << "斜率:" << S << endl;
}
bool operator||(const Line& l1, const Line& l2)
{
    return (l1.get_S() == l2.get_S() && !(l1 == l2)) ? true : false;
}
bool operator==(const Line& l1, const Line& l2)
{
    bool judger = (l1.get_S() == l2.get_S() && l1.get_X() == l2.get_X() &&
l1.get_Y() == l2.get_Y());
    return (judger) ? true : false;
}
int main()
{
    Line l1(1, 2, 3), l2(l1);
    cout << "l1:\n";
    l1.Print();
    cout << "l2:\n";
    l2.Print();
    cout << "请输入l2的X,Y,S新值:";
    int x, y;
    double s;
    cin >> x >> y >> s;
    l2.Set(x, y, s);
    cout << "l1:\n";
    l1.Print();
    cout << "l2:\n";
    l2.Print();
    if(l1 == l2) cout << "l1与l2重合\n";
    else cout << "l1与l2不重合\n";
    if(l1 || l2) cout << "l1与l2平行\n";
    else cout << "l1与l2不平行\n";
    return 0;
}