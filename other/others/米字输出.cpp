#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[100][100];
	int n, m;

	memset(str, '.', sizeof(str));

	cin >> n;
	m = 2 * n - 1 - 1;	//m=2n-1 - 1 arr_max_pos
	n -= 1;

	for (int i = 0; i < n; i++)
	{
		str[i][i] = str[m - i][i] = str[i][m - i] = str[m - i][m - i] = 'A' + i;
		str[i][n] = str[n][i] = str[n][m - i] = str[m - i][n] = str[i][i];
	}
	str[n][n] = 'A' + n;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
			cout << str[i][j];
		cout << endl;
	}

	return 0;
}
