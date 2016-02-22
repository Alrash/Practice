#include <iostream>
#include <cstdlib>

using namespace std;

struct Array
{
	int num;
	int pos;
};

int cmp(const void *a, const void *b)
{
	return (Array *)b->num - (Array *)a->num;
}

int main()
{
	int n. m;
	int start, end, k;
	Array *arr;

	cin >> n;
	arr = new *Array;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].num;
		arr[i].pos = i + 1;
	}

	qsort(arr, n, sizeof(Array), cmp);

	cin >> m;

	for (int i = 0, cot = 0; i < m; i++)
	{
		cin >> start >> end >> k;
		cot = 0;
		for (int j = 0; j < n; i++)
		{
			if (arr[j].pos >= start && arr[j].pos <= end)
			{
				cot++;
				if (cot == k)
				{
					cout << arr[j].num << endl;
					break;
				}
			}
		}
	}

	delete[] arr;
	return 0;
}
