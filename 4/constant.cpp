#include <iostream>
#define BUFLEN 5
using namespace std;
int main(int argc, char *argv[])
{
	int arr[BUFLEN];
	int i;

	for (i=0; i<BUFLEN; i++)
		arr[i] = BUFLEN-i;

	cout << "arr[0] = " << arr[0] << endl;
	cout << "arr[3] = " << arr[3] << endl;
	cout << "arr[7] = " << arr[7] << endl;

	return 0;
}