#include <iostream>
using namespace std;
int main()
{
    int m, n;
    int *a = new int[100];
    int a_sum = 0, b_sum = 0, c_sum = 0, d_sum = 0;
    for(int i = 0; i < 100; i++)
    {
        a[i] = i;
        a_sum +=a[i];
    }
    cout <<"a的和为：" << a_sum << endl;
    delete []a;
    int (*b)[25] = new int[20][25];
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            b[i][j] = i *25 + j;
            b_sum += b[i][j];
        }
        
    }
    cout << "b的和为：" << b_sum << endl;
    delete []b;
    int (*c)[8][5] = new int[9][8][5];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                c[i][j][k] = i * 100 + j * 10 + k;
                c_sum += c[i][j][k];
            }
        }
    }
    cout << "c的和为：" << c_sum << endl;
    delete []c;
    cout << "输入二维数组d的行和列：" << endl;
    cin >> m >> n;
    int (*d) = new int[m * n];//二维动态数组用一维代替
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            d[i * n + j] = i * n + j;
            d_sum += d[i * n + j];
        }
    }
    cout << "d的和为：" << d_sum << endl;
    delete []d;
    return 0;
}