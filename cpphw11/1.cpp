#include <iostream>
using namespace std;
int main()
{
    try
    {
        cout << "输入申请内存int:";
        int size;
        cin >> size;
        if(cin.fail())
        {
            throw("Input error!");
        }
        int* a = new(std::nothrow) int[size];
        if(a == NULL)
        {
            throw("Can't get memory!");
        }
        int index;
        cout << "输入数组访问元素:";
        cin >> index;
        if(index >= size)
        {
            throw("Array overflow!");
        }
        if(index < 0)
        {
            throw("Array underflow!");
        }
        a[index] = 10;
        if(a == NULL)
        {
            throw("Delete NULL!");
        }
        delete []a;
        cout << "访问数组一成功！" << endl << "数组二:";
        char* p = new(std::nothrow) char[9999999999999];
        if(p == NULL)
        {
            throw("Can't get memory!");
        }
        delete []p;
        cout << "成功.";
    }catch(const char* err)
    {
        cout << err;
    }
    return 0;
}