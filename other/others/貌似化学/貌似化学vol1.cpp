#include <iostream>
#include <algorithm>

using namespace std;

long long Math(long long arr[3][3])
{
	long long val = 0;
	int line[3] = { 12, 02, 01 }, sign = 1;
	int x, y;

	for (int i = 0; i < 3; i++)
	{
		x = line[i] / 10;
		y = line[i] % 10;

		val += sign * arr[0][i] * (arr[1][x] * arr[2][y] - arr[1][y] * arr[2][x]);

		sign *= -1;
	}

	return val;
}

int copy(long long arr[][4], long long tmp[][3], int pos)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0, n = 0; j < 4; j++)
			if (j != pos)
				tmp[i][n++] = arr[i][j];
	return 0;
}

long long min(long long val[])
{
	long long _min = val[3];

	for (int i = 0; i < 3; i++)
		if (_min > val[i] && val[i] != 0)
			_min = val[i];

	return _min;
}

int check(long long val[], long long num)
{
	int pos = 0;
	for (; pos < 4; pos++)
		if (val[pos] % num)
			break;

	return pos;
}

int div(long long val[], long long num)
{
	for (int i = 0; i < 4; i++)
		val[i] /= num;

	return 0;
}

int main()
{
	long long val[4];	//a, b, c, k
	int sign = 1;
	long long _min;
	long long arr[3][4], tmp[3][3];

	cin >> arr[0][3] >> arr[1][3] >> arr[2][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[j][i];

	for (int i = 0; i < 4; i++)
	{
		copy(arr, tmp, i);
		val[i] = Math(tmp);
	}

	if (val[3] != 0)
	{
		if (val[3] < 0)
			sign = -1;

		if (sign * val[1] <= 0)
		{
			int pos = 0;

			for (int i = 0; i < 4; i++)
				val[i] = abs(val[i]);

			_min = min(val);

			while ((_min % 2) == 0)
			{
				pos = check(val, 2);

				if (pos != 4)
					break;

				div(val, 2);
				_min /= 2;
			}

			for (int i = 3; i <= _min; i += 2)
			{
				pos = check(val, i);

				if (pos == 4)
				{
					div(val, i);
					_min /= i;
					i -= 2;
				}
			}

			for (int i = 0; i < 4; i++)
				cout << val[i] << " ";
		}
		else
			cout << "NONE";
	}
	else
		cout << "NONE";

	return 0;
}

