#include <iostream> std;
using namespace std;
int main()
{
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
    int n;
    cin >> n;

    int i = 2;

    while (i < n)
    {
        if (n % i == 0)
        {
            cout << "Not Prime for " << i << endl;
        }
        else
        {
            cout << "Prime for " << i << endl;
        }
        i = i + 1;
    }
}