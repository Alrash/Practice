#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

struct Node
{
	int a, b;		//a->值, b->index
};

const int INF = INT_MIN;
vector<Node> vt;

int fun(int len)
{
	int add = len * 1000;
	vector<vector<int> > dp(len + 1, vector<int>(add * 2 + 1, INF));
	set<int> ss;

	//init
	dp[0][add] = 0;
	dp[0][vt[0].b + add] = vt[0].a;
	ss.insert(add);
	ss.insert(vt[0].b + add);
	
	//calculator
	for (int i = 1; i < len; i++)
	{
		set<int> tmp;
		for (set<int>::iterator it = ss.begin(); it != ss.end(); it++)
		{
			dp[i][*it] = max(dp[i - 1][*it], dp[i][*it]);
			if (dp[i][*it + vt[i].b] != INF)
				if (*it != add)
					dp[i][*it + vt[i].b] = max(dp[i][*it + vt[i].b], dp[i][*it] + vt[i].a);
				else
					dp[i][*it + vt[i].b] = max(dp[i][*it + vt[i].b], vt[i].a);
			else
				dp[i][*it + vt[i].b] = vt[i].a + dp[i][*it];
			tmp.insert(*it + vt[i].b);
		}
		ss.insert(tmp.begin(), tmp.end());
	}

	int ans = 0;
	for (set<int>::reverse_iterator it = ss.rbegin(); it != ss.rend() && *it >= add; it++)
		if (dp[len - 1][*it] >= 0)
			ans = max(ans, dp[len - 1][*it] + *it - add);

	return ans;
}

int main()
{
	int n, len = 0;
	Node tmp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.a >> tmp.b;
		if (tmp.a >= 0 || tmp.b >= 0)	// === !(tmp.a < 0 && tmp.b < 0)
		{
			len++;
			vt.push_back(tmp);
		}
	}

	cout << fun(len) << endl;

	return 0;
}
