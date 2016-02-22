#include <iostream>
#include <cstdlib>

using namespace std;

int Copy(int des[], int sur[], int start, int end)
{
	for (int i = start, j = 0; i <= end; i++, j++)
		des[j] = sur[i];

	return 0;
}

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n, m;
	int *arr, *tmp;
	int start, end, k;

	cin >> n;
	arr = new int[n];
	tmp = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> k;
		Copy(tmp, arr, start - 1, end - 1);
		qsort(tmp,end - start + 1, sizeof(int), cmp);
		cout << tmp[k - 1] << endl;
	}

	delete[] arr;
	delete[] tmp;
	return 0;
}
