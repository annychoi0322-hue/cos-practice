#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int a, b, sum;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if (check_validity(a, b))
	{
		sum = sum_up(a, b);
	}
	return 0;
}