#include <iostream>

using namespace std;

int main()
{
	int n;
	int *arr, count, pos = 0;

	cin >> n;
	count = n;
	arr = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		if (i % 3 != 0)
			arr[i] = i;
		else
			arr[i] = -1;
	}

	count -= n / 3;
	pos = (n + 1) % 3;

	int i = 0;
	while (count != 1)
	{
		i++;
		if (i > n)
			i -= n;
		if (arr[i] == -1)
			continue;
		
		if (pos % 3 == 0)
		{
			arr[i] = -1;
			count--;
		}
		pos++;
	}

	for (i = 1; i <= n; i++)
		if (arr[i] != -1)
		{
			cout << arr[i];
			break;
		}

	delete[] arr;
	return 0;
}
