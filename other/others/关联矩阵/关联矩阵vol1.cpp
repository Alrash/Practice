#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int arr[100][100], edge[1000][100];
	int out[100][1000];
	int x, y;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = -1;

	for (int i = 0; i < m; i++)
		edge[i][0] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		if (arr[x][y] == -1)
			arr[x][y] = i;
		edge[arr[x][y]][0]++;
		edge[arr[x][y]][edge[arr[x][y]][0]] = i;
	}

	for (int i = 0; i < n; i++)
	{//注意内部for循环内的arr[x][y]是不同的
		for (int j = 0; j < n; j++)
			if (arr[i][j] != -1)
			{
				for (int x = 0; x < edge[arr[i][j]][0]; x++)
				out[i][edge[arr[i][j]][x + 1]] = 1;
			}

		for (int j = 0; j < n; j++)
			if (arr[j][i] != -1)
			{
				for (int x = 0; x < edge[arr[j][i]][0]; x++)
					out[i][edge[arr[j][i]][x + 1]] = -1;
			}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << out[i][j] << " ";
		cout << endl;
	}

	return 0;
}