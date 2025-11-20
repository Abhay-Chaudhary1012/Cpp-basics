#include <iostream>
using namespace std;
int main()
{
    // SUM OF NUMBERS

    /*
    int n;
    cout << "Enter the value of n: "   ;
    cin >> n;

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout<<sum<<endl;
*/

    // FIBONACCI SERIES

    /*
    int n ;
    cout<<"Enter the value of n :"<<endl;
    cin>>n;

    int a = 0;
    int b = 1;
    cout<<a<<" "<<b<<" ";

    for (int i = 1; i <= n; i++)
    {
        int nextNumber = a + b;
        cout << nextNumber << " ";
        a = b;
        b = nextNumber;
    }
*/
    // prime number or not

    /*
    int n;
    cout << "Enter the value of n :" << endl;
    cin >> n;

    bool isPrime = 1;

    for (int i = 2; i < n; i++)
    {
        // rem = 0 is not a prime
        if (n % i == 0)
        {
            // not a prime number
            isPrime = 0;
            break;
        }
    }
    if (isPrime == 0)
    {
        cout << "Not a prime number" << endl;
    }
    else
    {
        cout << "Is a prime number" << endl;
    }
*/
    
}