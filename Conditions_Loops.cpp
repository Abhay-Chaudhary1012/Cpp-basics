#include <iostream>
using namespace std;
int main()
{
    // int a;
    // cin >> a;
    //   cout<<"Value of n is :"<< n <<endl ;

    // if a is positive

    /*
    if(a>0){
        cout<<"A is positive"<<endl;
    }else{
        if(a<0)
        cout<<"A is Negative"<<endl;
    }
    */

    /*
    int a,b;

     cout<<"Enter the value of a"<<endl;
     cin>>a;
     cout<<"Enter the value of b"<<endl;
     cin>>b;

     if (a>b){
         cout<<"a is greater than b"<<endl;
     }
     if(a<b){
         cout<<"b is greater than a"<<endl;
     }
     */
    /*int a;

    cout << "Enter the value of a" << endl;

    cin >> a;

    if (a > 0)
    {
        cout << "a is greater than zero" << endl;
    }
    else
    {
        if (a < 0)
            cout << "a is less than zero" << endl;
        else
        {
            cout << "a is zero" << endl;
        }
    }
*/
    // sum of even interges
    int n, sum = 0, i = 2;

   std:: cout << "Enter the value of n: ";
  std::  cin >> n;

    while (i <= n) {
        sum += i;    // Add the even number to the sum
        i += 2;      // Increment by 2 to get the next even number
    }

   std:: cout << "Sum of even numbers till " << n << " is: " << sum << endl;

}
