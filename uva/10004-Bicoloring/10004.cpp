#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree[205];

bool BFS(int n)
{
	if (n == 1)
		return true;

	queue<int> que;
	int start;
	int visit[205];

	for (int i = 0; i < n; i++)
		visit[i] = 0;
	for (start = 0; tree[start].size() == 0; start++);
	que.push(start);
	visit[start] = 1;

	while (!que.empty())
	{
		int pos = que.front();
		que.pop();

		for (int i = 0; i < tree[pos].size(); i++)
		{
			if (visit[tree[pos][i]] == 0)
			{
				que.push(tree[pos][i]);
				if (visit[pos] == 1)
					visit[tree[pos][i]] = 2;
				else
					visit[tree[pos][i]] = 1;
			}
			else if (visit[tree[pos][i]] == visit[pos])
				return false;
		}
	}

	return true;
}

int main()
{
	int n, m;

	while (cin >> n && n && cin >> m)
	{
		int v, u;
		for (int i = 0; i < m; i++)
		{
			cin >> v >> u;
			tree[v].push_back(u);
			tree[u].push_back(v);
		}

		if (BFS(n))
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;

		for (int i = 0; i < n; i++)
			tree[i].clear();
	}

	return 0;
}
