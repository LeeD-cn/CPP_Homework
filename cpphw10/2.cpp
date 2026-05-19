#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main()
{
    ifstream is("2.txt", ios_base::in);
    int buf[128], count = 0, i = 1, num;
    char ch;
    if(!is.is_open()) 
    {
        cerr << "打开失败！";
        exit(0);
    }
    fstream os("2out.txt", ios_base::out | ios_base::binary | ios_base::in);
    while(i)
    {
        for(; count < 128;)
        {
            if(is >> buf[count])
            {
                count++;
            }
            else if(is.eof())
            {
                i = 0;
                break;
            }
            else
            {
                is.clear();
                is >> ch;
            }
        }
        os.write((char *)buf, count * sizeof(int));
        count = 0;
    }
    if(!os.is_open())
    {
        cout << "输出文件打开失败！";
        exit(0);
    }
    os.seekg(sizeof(int) * 4, ios_base::beg);
    count = 0;
    int j = 0;
    while(os.read((char *)&num, sizeof(int)))
    {  
        cout << left << setw(8) << num;
        count++;
        if(count % 2 == 0)
        {
            os.seekg(sizeof(int) * 2, ios_base::cur);
        }
        if(count % 10 == 0)
        {
            cout << endl;
        }
    }
    return 0;

    
}