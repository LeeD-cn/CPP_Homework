#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
class StrArr {
 public:
    StrArr(const char * filename)
    {
        is.open(filename, ios_base::in);
        if(!is.is_open())
        {
            cout << "文件打开失败！";
            exit(0);
        }
        size = 1, cursz = 0;
        arr = new Str[1];
    }
    class Str {
     public: 
        char * data;
        Str()
        {
            data = new char[81];
            strcpy(data, "");
        }
        ~Str()
        {
            delete []data;
        }
        const Str& operator=(const Str& other)
        {
            strcpy(data, other.data);
            return * this;
        }
    };
    void TranWrite(const char * filename)
    {
        ReadFile();
        Sort();
        Write(filename);
    }
    ~StrArr();
     private:
    void ReadFile();
    void Resize();
    void Sort();
    friend int cmp(const void * str1, const void * str2);
    void Write(const char * filename);
    ifstream is;
    ofstream os;
    Str * arr;
    int size, cursz;
};
void StrArr::Resize()
{
    if(cursz < size) return;
    else
    {
        int newsize = 2 * size;
        Str * newarr = new Str[newsize];
        for(int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete []arr;
        arr = newarr;
        size = newsize;
    }
}
void StrArr::ReadFile()
{
    while(1)
    {
        Resize();
        if(is >> arr[cursz].data)
        {
            cursz++;
        }
        if(!is.good())
        {
            break;
        }
    }
    return;
}
StrArr::~StrArr()
{
    delete []arr;
}
int cmp(const void * str1, const void * str2) 
{
    const char* s1 = ((StrArr::Str *)str1)->data;
    const char* s2 = ((StrArr::Str *)str2)->data;
    return strcmp(s1, s2); 
}
void StrArr::Sort()
{
    qsort(arr, cursz, sizeof(Str), cmp);
}
void StrArr::Write(const char * filename)
{

    os.open(filename, ios_base::out | ios_base::trunc);
    {
        for(int i = 0; i < cursz; i++)
        {
            os << i + 1 << '.' << arr[i].data << endl;
        }
    }
}
int main()
{
    StrArr book("3.txt");
    book.TranWrite("out.txt");
    return 0;
}