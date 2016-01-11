/* 10189扫雷
 * 实际是数组的更新
 * 例：4 4
 *     *...
 *     ....
 *     .*..
 *     ....
 * 输出:Field #1:
 *      *100
 *      2210
 *      1*10
 *      1110
 * */
#include <iostream>
#include <cstring>

using namespace std;

int out(int rect[][105], int line, int row, int n)
{
	if (n != 1)
		cout << endl;

	cout << "Field #" << n << ":\n";
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
			if (rect[i][j] == -1)
				cout << "*";
			else
				cout << rect[i][j];
		cout << endl;
	}

	return 0;
}

int main()
{
	int rect[105][105];
	int line, row;
	char ch;
	int count = 1;

	while (true)
	{
		cin >> row >> line;

		if (line == 0 && row == 0)
			break;

		memset(rect, 0, sizeof(rect));

		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= line; j++)
			{
				cin >> ch;
				if (ch == '*')
				{
					rect[i][j] = -1;

					//八个方向更新
					if (rect[i - 1][j - 1] != -1)
						rect[i - 1][j - 1]++;
					if (rect[i - 1][j] != -1)
						rect[i - 1][j]++;
					if (rect[i][j - 1] != -1)
						rect[i][j - 1]++;
					if (rect[i - 1][j + 1] != -1)
						rect[i - 1][j + 1]++;
					rect[i + 1][j - 1]++;
					rect[i + 1][j]++;
					rect[i][j + 1]++;
					rect[i + 1][j + 1]++;
				}
			}

		out(rect, line, row, count++);
	}
	return 0;
}
