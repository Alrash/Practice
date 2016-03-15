#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Node
{
	int a, b;

	Node()
	{
		a = b = 0;
	}

	Node operator+(const Node &node)
	{
		a += node.a;
		b += node.b;

		return *this;
	}
};

vector<Node> vt;

int main()
{
	int n;
	Node tmp;

	cin >> n;
	while (n--)
	{
		cin >> tmp.a >> tmp.b;
		if (tmp.a < 0 && tmp.b < 0)
			continue;
		vt.push_back(tmp);
	}

	int len = pow(2, vt.size());
	int ans = 0;
	vector<vector<Node> > dp(len + 1, vector<Node>(len));

	for (int i = 1; i <= vt.size(); i++)
	{
		int tmplen = pow(2, i);
		for (int j = 0; j < tmplen; j += 2)
		{
			dp[i][j] = dp[i - 1][j / 2];
			dp[i][j + 1] = dp[i - 1][j / 2 + 1] + vt[i - 1];
		}
	}

	for (int i = 0; i < len; i++)
		if (dp[vt.size()][i].a >= 0 && dp[vt.size()][i].b >= 0)
			ans = max(ans, dp[vt.size()][i].a + dp[vt.size()][i].b);

	cout << ans << endl;

	return 0;
}
