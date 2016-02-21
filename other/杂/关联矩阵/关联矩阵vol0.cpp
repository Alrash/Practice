#include <iostream>
#include <cstring>

using namespace std;

int map[101][1001];

int main(void) 
{
	int n, m;

	cin >> n >> m;

	memset(map, 0, sizeof(map));

	for (int j = 0; j < m; j++) 
	{
		int a, b;
		cin >> a >> b;
		map[a - 1][j] = 1;
		map[b - 1][j] = -1;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
			cout << map[i][j] << " ";
		cout << endl;
	}

	return 0;
}