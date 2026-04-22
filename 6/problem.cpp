#include <iostream>
using namespace std;

int check(int a, int b)
{
    return a<b;
}

int add(int a, int b)
{
    int i, c;
    c = 0;
    for (i=0; i<b; i++)
        c += i;
    return 0;
}

int main(){
    int a, b, result;
    cout << "insert the first number." << endl;
    cin >> a;
    cout << "insert the second number." << endl;
    cin >> b;

    if (check == 0)
        cout << "the result (a>=b):" << add(b,a) << endl;
    else
        cout << "the result (a < b): " << add(a, b) << endl;

    return 0;
}