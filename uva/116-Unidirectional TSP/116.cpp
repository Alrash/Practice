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
		dp[1][i] = min(dp[l][i - 1], dp[1][i - 1]);
		dp[1][i] = min(dp[1][i], dp[2][i - 1]) + vt[1][i];

		for (int j = 2; j < l; j++)
		{
			dp[j][i] = min(dp[j - 1][i - 1], dp[j][i - 1]);
			dp[j][i] = min(dp[j][i], dp[j + 1][i - 1]) + vt[j][i];
		}

		//最后一行的状态
		dp[l][i] = min(dp[l - 1][i - 1], dp[l][i - 1]);
		dp[l][i] = min(dp[l][i], dp[1][i - 1]) + vt[l][i];
	}
}

void out(int l, int c)
{
	int tmp = INT_MAX;

	for (int i = 1; i <= l; i++)
		tmp = min(tmp, dp[i][c]);

	cout << tmp << endl;
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
