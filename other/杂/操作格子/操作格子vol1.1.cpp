#include <iostream>
#include <cmath>

//#pragma comment(linker, "/STACK:16777216")

using namespace std;

struct Node
{
	int l, r;
	int max;
	int sum;
	int max_num;
};

int init(Node arr[], int left, int right, int i);
int insert(Node arr[], int num, int n, int i);
int Max(Node arr[], int left, int right, int &max, int i = 1);
int Sum(Node arr[], int left, int right, int &sum, int i = 1);
int replace(Node arr[], int n, int num, int nlen, int i = 1);

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

	init(arr, 1, n, 1);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		insert(arr, num, i + 1, 1);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> which >> pos1 >> pos2;
		switch (which)
		{
		case 1:
			replace(arr, pos1, pos2, n);
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

	//for (int i = 1; i <= 18; i++)
		//cout << arr[i].l << " " << arr[i].r << " " << arr[i].max << " " << arr[i].max_num << " " << arr[i].sum << endl;

	delete[] out;
	return 0;
}

int init(Node arr[], int left, int right, int i)
{
	arr[i].l = left;
	arr[i].r = right;
	arr[i].max = 0;
	arr[i].sum = 0;
	arr[i].max_num = 0;

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
	if (arr[i].max < num)
	{
		arr[i].max = num;
		arr[i].max_num = n;
	}
	arr[i].sum += num;

	if (n != arr[i].l || n != arr[i].r)
	{
		int mid = (arr[i].l + arr[i].r) / 2;
		if (n > mid)
			insert(arr, num, n, 2 * i + 1);
		else
			insert(arr, num, n, 2 * i);
	}
	return 0;
}

int Max(Node arr[], int left, int right, int &max, int i)
{
	if (left <= arr[i].max_num && right >= arr[i].max_num)
		if (max < arr[i].max)
			max = arr[i].max;

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

int fund(Node arr[],int list[], int n, int &count, int i = 1)
{
	list[count++] = i;
	if (arr[i].l != arr[i].r)
	{
		int mid = (arr[i].l + arr[i].r) / 2;
		if (mid >= n)
			fund(arr, list, n, count, 2 * i);
		else
			fund(arr, list, n, count, 2 * i + 1);
	}
	return 0;
}

int change(Node arr[], int i, int &max, int &max_num)
{
	if (max < arr[i].max)
	{
		max = arr[i].max;
		max_num = arr[i].max_num;
	}

	if (arr[i].l != arr[i].r)
	{
		change(arr, 2 * i, max, max_num);
		change(arr, 2 * i + 1, max, max_num);
	}
	return 0;
}

int replace(Node arr[], int n, int num, int nlen, int i)
{
	int len = (int)(nlen / log((double)nlen)) + 1, count = 0;
	int *exist = new int[len];
	int max = 0, max_num = 0;

	fund(arr, exist, n, count);

	arr[exist[count - 1]].max = num;
	arr[exist[count - 1]].sum = num;
	count--;
	for (int i = count - 1; i >= 0; i--)
	{
		arr[exist[i]].max = 0;
		arr[exist[i]].sum = arr[2 * exist[i]].sum + arr[2 * exist[i] + 1].sum;
		change(arr, exist[i], max, max_num);
		arr[exist[i]].max = max;
		arr[exist[i]].max_num = max_num;
		max = max_num = 0;
	}

	delete[] exist;
	return 0;
}