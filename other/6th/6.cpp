#include <iostream>

using namespace std;

int main()
{
	int a[50];
	for (int i = 0; i < 50; i++)
		a[i] = i;

	for (int i = 1; i < 49; i++)
		for (int j = i + 2; j < 49; j++)
			if (1225 - a[i] - a[i + 1]  - a[j] - a[j + 1] +
 					a[i] * a[i + 1] + a[j] * a[j + 1] == 2015)
				cout << i << endl;

	return 0;
}
