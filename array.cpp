#include<iostream>
using namespace std;
int main()
{
    // ARRAY BASICS

    /*
    int arr[5] = {1, 2, 3, 4, 5};

    // print array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    // INPUT IN ARRAY

    /*
    int arr[5];

    // taking input
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // print array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    // SUM OF ARRAY ELEMENTS

    int arr[5];
    int sum = 0;

    // taking input
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Sum is: " << sum << endl;

    return 0;
}