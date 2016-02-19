#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[9];
	for (int i = 1; i < 10; i++) a[i - 1] = i;

	do
	{
		int x = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		int y = a[4] * 10000 + a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[8];
		if (3 * x == y)
			cout << x << "/" << y << endl;
	}while(next_permutation(a, a + 9));

	return 0;
}
