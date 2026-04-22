#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    int pass = 0;
    char buff[20];

    cout << "Enter the password:  ";
    cin >> buff;

    if (strcmp(buff, "thegeekstuff")) {
        cout << "Wrong Password" << endl;
    } else {
        cout << "Correct Password" << endl;
        pass = 1;
    }

    if (pass){
        cout << "Root privileges given to the user" << std::endl;
    }

    cout << "buff (" << (void *)buff << ")= " << buff << endl;
    cout << "pass (" << (void *)&pass << ")= " << pass << std::endl;
    return 0;
}
