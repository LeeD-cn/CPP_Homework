#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define PI 3.14
using namespace std;
class Ball{
 public:
    Ball(int x = 0, int y = 0, int z = 0, int r = 1)
    : X(x), Y(y), Z(z), R(r){}
    Ball(const Ball& another)
    : X(another.X), Y(another.Y), Z(another.Z), R(another.R){}
    ~Ball()
    {
        cout << "析构Ball(" << X << ',' << Y << ',' << Z << ')' << endl;
    }
    void Set(int, int, int, int);
    int GetX() const;
    int GetY() const;
    int GetZ() const;
    int GetR() const;
    void Print() const;
    double Volume() const;
 private:
    int X, Y, Z, R;
};
void Ball::Set(int x, int y, int z, int r)
{
    X = x;
    Y = y;
    Z = z;
    R = r;
}
int Ball::GetX() const
{
    return X;
}
int Ball::GetY() const
{
    return Y;
}
int Ball::GetZ() const
{
    return Z;
}
int Ball::GetR() const
{
    return R;
}
void Ball::Print() const
{
    cout << "Ball: 球心坐标(" << X << ',' << Y << ',' << Z << "); 球半径：" << R << endl;
}
double Ball::Volume() const
{
    double v = (PI * 4 / 3) * R * R * R;
    return v;
}
int ball_cmp(const void* a, const void* b)
{

    return ((Ball*)a)->GetR() - ((Ball*)b)->GetR();
}
int main()
{
    srand(time(0));
    int i, x, y, z, r;
    class Average{
     public:
        Average()
        : x(0), y(0), z(0), r(0), counter(0), v(0){}
        void count(const Ball& ball)
        {
            x += ball.GetX();
            y += ball.GetY();
            z += ball.GetZ();
            r += ball.GetR();
            v += ball.Volume();
            counter ++;
        }
        void print_average()
        {
            cout << "平均球心坐标:(" << x / counter << ',' << y / counter << ',' << z / counter << "); 平均半径:" 
            << r / counter << "; 平均体积:" << fixed << setprecision(2) << v / counter << endl; 
        }
     private:
        int x, y, z, r, counter;
        double v;
    };
    Average avrg;
    Ball b1[10];
    cout << "随机化静态对象数组中。。。" << endl;
    for(i = 0; i < 10; i++)
    {
        x = rand();
        y = rand();
        z = rand();
        r = abs(rand()) % 100;
        b1[i].Set(x, y, z, r);
        cout << i + 1 << '.';
        b1[i].Print();
        avrg.count(b1[i]);
    }
    qsort(b1, 10, sizeof(Ball), ball_cmp);
    cout << "-----------------------------\n" <<"按半径升序排列后\n" << "-----------------------------\n";
    for(i = 0; i < 10; i++)
    {
        cout << i + 1 << '.';
        b1[i].Print();
    }
    Ball *b2 = new Ball[20];
    cout << "随机化动态对象数组中。。。" << endl;
    for(i = 0; i < 20; i++)
    {
        x = rand();
        y = rand();
        z = rand();
        r = abs(rand()) % 100;
        b2[i].Set(x, y, z, r);
        cout << i + 1 << '.';
        b2[i].Print();
        avrg.count(b2[i]);
    }
    qsort(b2, 20, sizeof(Ball), ball_cmp);
    cout << "-----------------------------\n" <<"按半径升序排列后\n" << "-----------------------------\n";
    for(i = 0; i < 20; i++)
    {
        cout << i + 1 << '.';
        b2[i].Print();
    }
    cout << "所有Ball平均值:";
    avrg.print_average();
    delete []b2;
    return 0;
}