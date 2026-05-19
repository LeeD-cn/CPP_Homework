#include <iostream>
#include <iomanip>
#define PI 3.14
using namespace std;
class Circle{
public:
    Circle(double x, double y, double r = 1)
    {
        cout << "调用构造函数" << endl;
        center_x = x;
        center_y = y;
        radius = r;
    }
    Circle(const Circle &other)
    {
        cout << "调用复制构造函数" << endl;
        center_x = other.center_x;
        center_y = other.center_y;
        radius = other.radius;
    }
    ~Circle()
    {
        cout << "调用圆析构函数" << endl;
    }
    void Set(double x, double y, double r);
    void Print();
    double Area()
    {
        return (PI * radius * radius);
    }
private:
    double center_x, center_y;
    double radius;
};
void Circle::Set(double x, double y, double r)
{
    center_x = x;
    center_y = y;
    radius = r;
}
void Circle::Print()
{
    cout << "圆心坐标:(" << center_x << "," << center_y << ")" << endl;
    cout << "半径 = " << setprecision(6) << radius << endl;
}
int main()
{
    int x, y, r;
    cout << "请分别输入横纵坐标和半径：";
    cin >> x >> y >> r;
    Circle a(x, y, r);
    Circle b(a);
    cout << "a的面积是:" << a.Area() << endl; 
    cout << "a:";
    a.Print();
    cout << "b:";
    b.Print();
    cout << "请重新输入b的横纵坐标和半径：";
    cin >> x >> y >> r;
    b.Set(x, y, r);
    cout << "b:";
    b.Print();
    return 0;
}