#include <iostream>
using namespace std;

extern "C" int sum(int a, int b);

int main() { 
    int a, b, c;
    a = 3; b = 5; 
    c = sum(a, b);
    cout << "c: " << c << endl;

    return 0;
}
