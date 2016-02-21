#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

int main()
{
	int arr[8][2], n;
	int final_num = INT_MAX, _max, num = 0;
	int white[8], black = 0, cot = 0;
	bool fail;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
	_max = (int)pow(2, n);

	for (int i = 0, tmp; i < _max; i++)
	{
		tmp = i;
		black = 0;
		for (int j = 0; j < n; j++)
		{
			white[j] = tmp % 2;
			if (white[j] == 0)
				black++;
			tmp /= 2;
		}

		num = 0;
		fail = false;

		for (int j = 0; j < n; j++)
		{
			if (white[j])
			{
				if (arr[j][1] != black)
				{
					fail = true;
					break;
				}
				else
				{
					num = num * 10 + j + 1;
				}
			}
			else
			{
				if (arr[j][1] == (black - 1))
				{
					fail = true;
					break;
				}
			}
		}

		if (fail == false)
		{
			if (num == 0)
			{
				final_num = 0;
				break;
			}

			final_num = min(final_num, num);
		}
	}

	if (final_num == INT_MAX)
		cout << "NoSolution.";
	else
		cout << final_num;

	return 0;
}
