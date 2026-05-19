#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
class Matrix{
 public:
    Matrix();
    Matrix(const Matrix&);
    ~Matrix();
    friend Matrix operator +(const Matrix&, const Matrix&);
    friend Matrix operator -(const Matrix&, const Matrix&);
    friend void print_matrix(const Matrix&);
 private:
    int *p;
    int m, n;
    bool iscophenetic(const Matrix&) const;
};
Matrix::Matrix()
{
    cout << "请分别输入矩阵的行数和列数:";
    cin >> m >> n;
    p = new int[m * n];
    cout << "请输入矩阵的元素:" << endl;
    for(int i = 0; i < m; i++)
    {
        cout << "第" << i + 1 << "行（共" << n << "个）：" << endl;
        for(int j = 0; j < n; j++)
        {
            cin >> p[n * i + j];
        }
    }
}
Matrix::Matrix(const Matrix& another)
{
    m = another.m;
    n = another.n;
    p = new int[m * n];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            p[n * i + j] = another.p[m * i + j];
        }
    }
}
Matrix::~Matrix()
{
    delete []p;
}
bool Matrix::iscophenetic(const Matrix& another) const
{
    bool result = false;
    if(m == another.m && n == another.n) result = true;
    return result;
}
Matrix operator +(const Matrix& M1, const Matrix& M2)
{
    if(!M1.iscophenetic(M2))
    {
        cout << "矩阵不同型！" << endl;
        exit(0);
    }
    Matrix MT(M1);
    for(int i = 0; i < M1.m; i++)
    {
        for(int j = 0; j < M1.n; j++)
        {
            MT.p[i * M1.n + j] += M2.p[i * M1.n + j];
        }
    }
    return MT;
}
Matrix operator -(const Matrix& M1, const Matrix& M2)
{
    if(!M1.iscophenetic(M2))
    {
        cout << "矩阵不同型！" << endl;
        exit(0);
    }
    Matrix MT(M1);
    for(int i = 0; i < M1.m; i++)
    {
        for(int j = 0; j < M1.n; j++)
        {
            MT.p[i * M1.n + j] -= M2.p[i * M1.n + j];
        }
    }
    return MT;
}
void print_matrix(const Matrix& M)
{
    for(int i = 0; i < M.m; i++)
    {
        for(int j = 0; j < M.n; j++)
        {
            cout << left << setw(4) << M.p[i * M.n + j];
        }
        cout << endl;
    }
}
int main()
{
    Matrix M1, M2;
    cout << "M1 + M2 = " << endl;
    print_matrix(M1 + M2);
    cout << "M1 - M2 = " << endl;
    print_matrix(M1 - M2);
    return 0;
}