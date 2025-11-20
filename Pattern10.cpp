#include <iostream>
using namespace std;
main()
{
    int n;
    cin >> n;

    char value = 'A';

    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << value 
            <<"  ";
            value = value + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}