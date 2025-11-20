#include <iostream>
using namespace std;
int main()
{

    int a = 4, b = 6;

    cout << " a&b " << (a & b) << endl;
    cout << " a|b " << (a | b) << endl;
    cout << " ~a " << (~a) << endl;
    cout << " a^b " << (a ^ b) << endl;

    cout << (5 << 1) << endl;
    cout << (5 << 2) << endl;
    cout << (10 >> 1) << endl;
    cout << (10 >> 2) << endl;

    int i = 3;
    cout << (i++) << endl;
    // 3,i=4
    cout << (i--) << endl;
    // 4,i=3
    cout << (--i) << endl;
    // 2,i=2
    cout << (++i) << endl;
    // 3,i=3
}
