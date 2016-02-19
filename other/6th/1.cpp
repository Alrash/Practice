#include <iostream>

using namespace std;

bool isContainFour(int n)
{
	do
	{
		if (n % 10 == 4)
			return true;
		n /= 10;
	}while(n);

	return false;
}

int main()
{
	int count = 0;

	for (int i = 10000; i < 100000; i++)
		if (!isContainFour(i))
			count++;

	cout << count << endl;

	return 0;
}
