#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>

#define N 10005

using namespace std;

vector<vector<int> > vt(N, vector<int>(N));
vector<vector<int> > dp(N, vector<int>(N));
vector<vector<int> > ans(N, vector<int>(N));

void findLeast(int l, int c)
{
	for (int i = 1; i <= c; i++)
	{
		//第一行的状态
		if (dp[l][i - 1] < dp[1][i - 1])
		{
			dp[1][i] = dp[l][i - 1];
			ans[1][i] = 1;
		}
		else
		{
			dp[1][i] = dp[1][i - 1];
			ans[1][i] = 2;
		}
		if (dp[1][i] > dp[2][i - 1])
		{
			dp[1][i] = dp[2][i - 1];
			ans[1][i] = 3;
		}
		dp[1][i] += vt[1][i];

		for (int j = 2; j < l; j++)
		{
			if (dp[j - 1][i - 1] <= dp[j][i - 1])
			{
				dp[j][i] = dp[j - 1][i - 1];
				ans[j][i] = 1;
			}
			else
			{
				dp[j][i] = dp[j][i - 1];
				ans[j][i] = 2;
			}
			if (dp[j][i] > dp[j + 1][i - 1])
			{
				dp[j][i] = dp[j + 1][i - 1];
				ans[j][i] = 3;
			}
			dp[j][i] += vt[j][i];
		}

		//最后一行的状态
		if (dp[l - 1][i - 1] <= dp[l][i - 1])
		{
			dp[l][i] = dp[l - 1][i - 1];
			ans[l][i] = 1;
		}
		else
		{
			dp[l][i] = dp[l][i - 1];
			ans[l][i] = 2;
		}
		if (dp[l][i] > dp[1][i - 1])
		{
			dp[l][i] = dp[1][i - 1];
			ans[l][i] = 3;
		}
		dp[l][i] += vt[l][i];
	}
}

void outPrintPath(int x, int y, int l)
{
	if (y == 0)
		return;

	if (ans[x][y] == 1)
		if (x - 1 == 0)
			outPrintPath(l, y - 1, l);
		else
			outPrintPath(x - 1, y - 1, l);
	if (ans[x][y] == 2)
		outPrintPath(x, y - 1, l);
	if (ans[x][y] == 3)
		if (x + 1 > l)
			outPrintPath(1, y - 1, l);
		else
			outPrintPath(x + 1, y - 1, l);

	cout << x << " ";
}

void out(int l, int c)
{
	int tmp = INT_MAX, pos;

	for (int i = 1; i <= l; i++)
		if (tmp > dp[i][c])
		{
			tmp = dp[i][c];
			pos = i;
		}

	outPrintPath(pos, c, l);

	cout << endl << tmp << endl;
}

int main()
{
	int l, c;

	while (scanf("%d%d", &l, &c) == 2)
	{
		//init
		for (int i = 0; i <= l; i++)
			for (int j = 0; j <= c; j++)
				ans[i][j] = dp[i][j] = 0;

		for (int i = 1; i <= l; i++)
			for (int j = 1; j <= c; j++)
				cin >> vt[i][j];

		findLeast(l, c);
		out(l, c);
	}

	return 0;
}
