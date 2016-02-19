#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[10000 + 5];
vector<int> value;
int n;
int visit[10000 + 5];
int dp[10000 + 5], ans = 0;

void dfs(int p)
{
	visit[p] = 1;
	for (int i = 0; i < tree[p].size(); i++)
	{
		int v = tree[p][i];
		if (!visit[v])
		{
			dfs(v);
			if (dp[v] > 0)
				dp[p] += dp[v];
		}
	}
	ans = max(dp[p], ans);
	visit[p] = 0;
}

int main()
{
	int tmp;

	cin >> n;
	value.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		value.push_back(tmp);
		dp[i + 1] = tmp;
	}

	for (int i = 1, a, b; i < n; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 0; i <= n; i++)
		visit[i] = 0;

	dfs(1);

	cout << ans << endl;

	return 0;
}
