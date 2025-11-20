#include <iostream>
using namespace std;
main()
{
    /*
    cout << "      1" <<endl ;
     cout << "     121" <<endl ;
     cout << "    12321" <<endl ;
     cout << "   1234321" <<endl ;
 */
    // by while loop
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        // space

        int space = n - i;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }
        // 1st triangle
        int j = 1;
        while (j <= i)
        {
            cout << j;
            j = j + 1;
        }
        // printing 2nd triangle
            int start = i-1;
            while(start){
                cout<<start;
                start=start-1;
            }
        cout << endl;
        i = i + 1;
    }
}