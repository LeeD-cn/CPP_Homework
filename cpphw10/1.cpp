#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int num, count =0;
    char ch;
    ifstream is("1.txt", ios_base::in);
    if (!is.is_open()) 
    {
        cerr << "无法打开文件" << endl;
        return 1;
    }
    while(1)
    {
        if(is >> num)
        {
            cout << setw(8) << num;
            count++;
            if(count % 10 == 0)
            {
               cout << endl;
            }
        }
        else if(is.eof())
        {
            break;
        }
        else
        {
            is.clear();
            is >> ch;
        }
    }
    return 0;
}