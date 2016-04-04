#include <iostream>

using namespace std;

int main()
{
	int n, value = 1, tmp;

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		value *= i;
		if (value % 10 == 0)
		{
			do
			{
				value /= 10;
			} while (value % 10 == 0);
		}
		else
			value %= 1000;
	}

	cout << value % 10;

	return 0;
}