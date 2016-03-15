#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node
{
	int a, b;		//a->Öµ, b->index
};

const int INF = INT_MIN;
vector<Node> vt;

int getAns(int len)
{
	int add = len * 1000, end = add * 2 + 1;
	vector<vector<int> > dp(len + 1, vector<int>(end, INF));

	//init
	//dp[0][add] = 0;
	dp[0][vt[0].b + add] = vt[0].a;
	
	//calculator
	for (int i = 1; i < len; i++)
	{
		for (int j = 0, pos; j < end; j++)
			if (j == add && dp[i - 1][j] == INF)
			{
				dp[i][j + vt[i].b] = max(vt[i].a, dp[i][j + vt[i].b]);
			}
			else if (dp[i - 1][j] != INF)
			{
				dp[i][j] = dp[i - 1][j];
				dp[i][j + vt[i].b] = max(dp[i][j + vt[i].b], dp[i - 1][j] + vt[i].a);
			}
	}

	/*for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < end; j++)
			if (dp[i][j] != INF)
				cout << dp[i][j] << "+" << j - add << " ";
		cout << endl;
	}*/

	int ans = 0;
	for (int j = end - 1; j >= add; j--)
		if (dp[len - 1][j] >= 0)
			ans = max(dp[len - 1][j] + j - add, ans);		//a+b, ans
	
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

	cout << getAns(len) << endl;

	return 0;
}
