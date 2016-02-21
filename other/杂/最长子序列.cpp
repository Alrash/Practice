/*对无序数求最长递增序列个数
 *未求那一对
 */
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Array
{
	int pos;
	int num;
};

int cmp(const void *a, const void *b)
{
	return ((Array *)a)->num - ((Array *)b)->num;
}

int main()
{
	int len, count = 0;
	Array *arr;
	int *list;

	cin >> len;
	arr = new Array[len + 1];
	list = new int[len + 1];

	arr[0].num = INT_MAX;
	arr[0].pos = 0;
	for (int i = 1; i <= len; i++)
	{
		cin >> arr[i].num;
		arr[i].pos = i;
	}

	qsort(arr + 1, len, sizeof(Array), cmp);

	/*for (int i = 0; i <= len; i++)
		cout << arr[i].num << " ";
	cout << endl;
	for (int i = 0; i <= len; i++)
		cout << arr[i].pos << " ";
	cout << endl;*/

	list[0] = -1;
	list[1] = 0;
	for (int i = 2; i <= len; i++)
	{
		int j = i - 1;
		for (; arr[i].pos < arr[j].pos; j--);

		list[i] = list[j] + 1;

		count = max(count, list[i]);
	}

	/*for (int i = 0; i <= len; i++)
		cout << list[i] << " ";
	cout << endl;*/

	cout << count + 1;

	delete[] list;
	delete[] arr;
	return 0;
}
