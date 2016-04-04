#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
	int pos1, pos2;
	int time;
};

int *father;

int cmp(const void *a, const void *b)
{
	return ((node *)a)->time - ((node *)b)->time;
}

int getfather(int &child)
{
	if (child != father[child])
		father[child] = getfather(father[child]);

	return father[child];
}

int main()
{
	int n, l;
	int *time;
	node *arr;
	int _min = INT_MAX, sum = 0;

	cin >> n >> l;
	time = new int[n];
	father = new int[n];
	arr = new node[l];

	for (int i = 0; i < n; i++)
	{
		cin >> time[i];
		father[i] = i;
		_min = min(_min, time[i]);
	}

	sum += _min;

	for (int i = 0, pos = 0; i < l; i++)
	{
		cin >> arr[i].pos1 >> arr[i].pos2 >> arr[i].time;
		arr[i].pos1--;
		arr[i].pos2--;
		arr[i].time = time[arr[i].pos1] + time[arr[i].pos2] + (arr[i].time << 1);
	}

	qsort(arr, l, sizeof(node), cmp);

	for (int i = 0, j = 1, pos1, pos2;j < n; i++)
	{
		pos1 = getfather(arr[i].pos1);
		pos2 = getfather(arr[i].pos2);

		if (pos1 != pos2)
		{
			j++;
			father[pos1] = pos2;
			sum += arr[i].time;
		}
	}

	cout << sum;

	delete[] father;
	delete[] time;
	delete[] arr;

	return 0;
}
