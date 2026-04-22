#include <iostream>
using namespace std;

extern "C" int run();

int main() { 
    cout << "The skeleton code for the assembly language" << endl;
    cout << "return value: " << run() << endl; 
    return 0;
}
