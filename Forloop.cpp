#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of n :" << " ";
 //   cin >> n;

    cout << "Printing counting from 1 to n" << endl;

    /*
    for (int i = 1; i<=n; i++)
    {
        cout<<i<<endl;
    }
    */

    // now we are doing the same without putting them inside bracket

/*  
int i = 1;
    for (;;)
    {
        if (i <= n)
        {
            cout << i << endl;
        }
        else{
            break;
        }

        i++;
    }
    */
   // now applying more than one initialiser condtion and updation#

   for( int a=0 , b =1; a>=0 , b >=1; a-- , b--)
   {    
    cout<<a<<" "<<b<<""<<endl;
   }
}