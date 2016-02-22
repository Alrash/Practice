/*本题为：只要max-min = R - L + 1就行，并且内部连续，无需前一个也连续*/
#include <iostream>
#include <algorithm>

using namespace std;

int len, _count = 0;
int *arr;

int fund(int pos, int _min, int _max)
{
	for (int i = pos + 1; i < len; i++)
	{
		_max = max(arr[i], _max);
		_min = min(arr[i], _min);
		if (_max - _min == i - pos)
		{
			_count++;
		}
	}
	return 0;
}

int main()
{
	int _max, _min;

	cin >> len;
	arr = new int[len];
	_count += len;

	for (int i = 0; i < len; i++)
		cin >> arr[i];

	for (int i = 0; i < len; i++)
	{
		_min = _max = arr[i];
		fund(i, _min, _max);
	}

	cout << _count;

	delete[] arr;
	return 0;
}
