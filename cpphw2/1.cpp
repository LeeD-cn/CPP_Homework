#include <iostream>
#include <iomanip>
using namespace std;
const int n = 10;
int main()
{
    int num[10] = {0};
    for(int i = 0; i < n; i++)
    {
        cout << setw(2*(n - i + 1)) << ' ';
        for(int j = i; j >= 0; j--)
        {
            if(j == 0 || j == i)
            {
                num[j] = 1;
            }
            else
            {
                num[j] = num[j] + num[j - 1];
            }
        }
        for(int k = 0; k <= i; k++)
        {
            cout << setw(4) << num[k];
        }
        cout << endl;
    }
    return 0;
}