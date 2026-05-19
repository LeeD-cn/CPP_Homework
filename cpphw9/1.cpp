#include <iostream>
using namespace std;
template<typename T1, typename T2, typename T3>
auto Max(T1 a, T2 b, T3 c)
{
    auto t = (a > b) ? a : b;
    auto max = (t > c) ? t : c;
    return max;
}
int main()
{
    cout << Max('s', 3, 100.89) << endl;
    cout << Max(5L, 3.9f, 3.99) << endl;
    cout << Max(short(89), 'A', 80000ll) << endl;
    return 0;
}