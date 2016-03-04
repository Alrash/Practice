#include <iostream>
#include <algorithm>

using namespace std;

int a[12] = {1, 8, 2, 4, 5, 6, 7, 9, 10, 11, 12, 3};

bool isAns()
{
	int sum[6];
	sum[0] = a[0] + a[2] + a[5] + a[7];
	sum[1] = a[0] + a[3] + a[6] + a[10];
	sum[2] = a[1] + a[2] + a[3] + a[4];
	sum[3] = a[1] + a[5] + a[8] + a[11];
	sum[4] = a[4] + a[6] + a[9] + a[11];
	sum[5] = a[7] + a[8] + a[9] + a[10];

	//sort(sum, sum + 6);
	if (min_element(sum, sum + 6) != max_element(sum, sum + 6))
		return false;

	//if (sum[0] != sum[5])
	//	return false;
	return true;
}

int main()
{
	//for (int i = 0; i < 12; i++)
	//	a[i] = i + 1;

	do
	{
		//if (a[0] != 1 && a[11] != 3 && a[1] != 8)
		//	continue;

		if (isAns())
		{
			cout << a[5] << endl;
			break;
		}

	} while (next_permutation(a + 1, a + 11));

	return 0;
}
