#include <iostream>

using namespace std;

struct Node
{
	int l, r;
	int max;
	int sum;
};

int init(Node arr[], int left, int right, int i = 1);
int insert(Node arr[], int num, int n, int i = 1);
int Max(Node arr[], int left, int right, int &max, int i = 1);
int Sum(Node arr[], int left, int right, int &sum, int i = 1);

int main() 
{
	int n, m;
	int *out, count = 0;
	Node arr[30000];
	int num, which, pos1, pos2;

	cin >> n >> m;
	out = new int[m];
	for (int i = 0; i < m; i++)
		out[i] = 0;

	init(arr, 1, n);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		insert(arr, num, i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> which >> pos1 >> pos2;
		switch (which)
		{
		case 1:
			insert(arr, pos2, pos1);
			break;
		case 2:
			Sum(arr, pos1, pos2, out[count]);
			count++;
			break;
		case 3:
			Max(arr, pos1, pos2, out[count]);
			count++;
			break;
		}
	}

	for (int i = 0; i < count; i++)
		cout << out[i] << endl;

	delete[] out;
	return 0;
}

int init(Node arr[], int left, int right, int i)
{
	arr[i].l = left;
	arr[i].r = right;
	arr[i].max = 0;
	arr[i].sum = 0;

	if (left != right)
	{
		int mid = (left + right) / 2;
		init(arr, left, mid, 2 * i);
		init(arr, mid + 1, right, 2 * i + 1);
	}
	return 0;
}

int insert(Node arr[], int num, int n, int i)
{
	if (arr[i].l <= n && n <= arr[i].r)
	{
		arr[i].max = num;
		arr[i].sum = num;
	}

	if (arr[i].l == arr[i].r)
		return 0;
	
	int mid = (arr[i].l + arr[i].r) / 2, pos = 0;
	if (n > mid)
		insert(arr, num, n, 2 * i + 1);
	else
		insert(arr, num, n, 2 * i);
	
	arr[i].sum = arr[2 * i].sum + arr[2 * i + 1].sum;
	pos = 2 * i;
	arr[i].max = arr[pos].max > arr[pos + 1].max ? arr[pos].max : arr[pos + 1].max;

	return 0;
}

int Max(Node arr[], int left, int right, int &max, int i)
{
	if (arr[i].l != left || arr[i].r != right)
	{
		int mid = (arr[i].l + arr[i].r) / 2;
		if (left > mid)
			Max(arr, left, right, max, 2 * i + 1);
		else
		{
			if (right <= mid)
				Max(arr, left, right, max, 2 * i);
			else
			{
				Max(arr, left, mid, max, 2 * i);
				Max(arr, mid + 1, right, max, 2 * i + 1);
			}
		}
	}
	else
	{
		if (max < arr[i].max)
			max = arr[i].max;
	}
	return 0;
}

int Sum(Node arr[], int left, int right, int &sum, int i)
{
	if (arr[i].l != left || arr[i].r != right)
	{
		int mid = (arr[i].l + arr[i].r) / 2;
		if (left > mid)
			Sum(arr, left, right, sum, 2 * i + 1);
		else
		{
			if (right <= mid)
				Sum(arr, left, right, sum, 2 * i);
			else
			{
				Sum(arr, left, mid, sum, 2 * i);
				Sum(arr, mid + 1, right, sum, 2 * i + 1);
			}
		}
	}
	else
		sum += arr[i].sum;
	return 0;
}