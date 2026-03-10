#include <iostream>
#include <iomanip>
using namespace std;
void print_color(int, int, int);
void color(int);
int main()
{
    int count = 0;
    for(int i = 0; i < 7; i++)
    {
        for(int j = i + 1; j < 7; j++)
        {
            for(int k = j + 1; k < 7; k++)
            {
                count ++;
                cout << setw(2) << count << '.';
                print_color(i, j, k);
            }
        }
    }
    cout << "¹²" << count << "ÖÖ¡£" << endl;
    return 0;
}
void print_color(int i, int j, int k)
{
    color(i);
    cout << "¡¢";
    color(j);
    cout << "¡¢";
    color(k);
    cout << endl;
}
void color(int i)
{
    switch(i)
    {
        case 0: cout << "ºì"; break;
        case 1: cout << "³È"; break;
        case 2: cout << "»Æ"; break;
        case 3: cout << "ÂÌ"; break;
        case 4: cout << "Çà"; break;
        case 5: cout << "À¶"; break;
        case 6: cout << "×Ï"; break;
    }
}