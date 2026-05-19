#include <iostream>
#include <cstdlib>
using namespace std;
class Rectangle{
public:
    Rectangle(double x_1 = 0, double y_1 = 0, double x_2 = 0, double y_2 = 0)
    {
        if(x_1 > x_2 || y_1 > y_2) 
        {
            cout << "输入错误，创建失败！";
            exit(0);
        }
        x1 = x_1, y1 = y_1, x2 = x_2, y2 = y_2;
    }
    Rectangle(const Rectangle &R)
    {
        x1 = R.x1, x2 = R.x2, y1 = R.y1, y2 = R.y2;
    }
    ~Rectangle()
    {
        cout << "析构Rectangle对象" << endl;
    }
    void Set(double x_1, double y_1, double x_2, double y_2);
    void Print();
    double Area();
    double get_X_Length() const;
    double get_Y_Width() const;
    void Translate(double dx, double dy);
    bool Issquare() const;
private:
    double x1, y1, x2, y2;
};
void Rectangle::Set(double x_1, double y_1, double x_2, double y_2)
{
    x1 = x_1, y1 = y_1, x2 = x_2, y2 = y_2;
}
void Rectangle::Print()
{
    cout << "左下角点坐标:(" << x1 << "," << y1 << "); 右下角点坐标:(" << x2 << "," << y2 << ");" << endl; 
}
double Rectangle::Area()
{
    double area = (x2 - x1) * (y2 - y1);
    return area;
}
double Rectangle::get_X_Length() const
{
    return x2 - x1;
}
double Rectangle::get_Y_Width() const
{
    return y2 - y1;
}
void Rectangle::Translate(double dx, double dy)
{
    x1 += dx;
    x2 += dx;
    y1 += dy;
    y2 += dy;
}
bool Rectangle::Issquare() const
{
    bool result = false;
    if(get_X_Length() == get_Y_Width())
    {
        result = true;
    }
    return result;
}
int main()
{
    Rectangle a(0, 0, 4, 5);
    Rectangle b(a);
    b.Set(1, 1, 3, 3);
    if(b.Issquare())
    {
        cout << "b是正方形！" << endl;
    }
    a.Print();
    a.Translate(1, 1);
    a.Print();
    cout << "a的面积为:" << a.Area() << endl;
    return 0;
}