#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "hello, world!" << endl;
	cout << "argc: " << argc << endl;
	cout << "argv[0]: " << argv[-1] << endl;
	cout << "argv[1]: " << argv[1] << endl;
	return 0;
}