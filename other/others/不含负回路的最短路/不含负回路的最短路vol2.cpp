#include <iostream>
#include <deque>
#include <vector>

#define INF 200000

using namespace std;

struct Edge
{
	int to, weight;
};

vector<Edge> adjmap[20005];
int N, E;
int dis[20005];
bool in[20005];

int SPFA()
{
	deque<int> dq;
	int from, to;

	in[1] = true;
	dis[1] = 0;
	dq.push_back(1);

	while (!dp.empty())
	{
		from = dp.front();
		dp.pop_front();
		in[from] = false;

		for (int i = 0; i < adjmap[from].size(); i++)
		{
			to = adjmap[from][i].to;
			if (dis[to] > dis[from] + adjmap[from][i].weight)
			{
				dis[to] = dis[from] + adjmap[from][i].weight;
				if (!in[to])
				{
					in[to] = true;
					if (!dp.empty())
						if (dis[to] > dis[dq.front()])
							dq.push_back(to);
						else
							dq.push_front(to);
					else
						dq.push_back(to);
				}
			}
		}
	}

	return 0;
}

int main()
{
	Edge tmp;
	int from;

	cin >> N >> E;

	for (int i = 1; i <= N; i++)
	{
		adjmap[i].clear();
		dis[i] = INF;
		in[i] = false;
	}

	for (int i = 0; i < E; i++)
	{
		cin >> from >> tmp.to >> tmp.weight;
		adjmap[from].push_back = tmp;
	}

	SPFA();

	for (int i = 2; i <= N; i++)
		cout << dis[i] << endl;

	return 0;
}
