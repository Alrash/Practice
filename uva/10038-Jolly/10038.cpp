#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n;
	int arr[3005], diff[3000];

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		if (n == 1)
		{
			printf("Jolly\n");
			continue;
		}

		for (int i = 1; i < n; i++)
			diff[i - 1] = abs(arr[i] - arr[i - 1]);
		
		qsort(diff, n - 1, sizeof(int), cmp);
		
		int i = 0;
		for (; i < n - 1; i++)
			if (diff[i] != i + 1)
				break;

		if (i == n - 1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}
