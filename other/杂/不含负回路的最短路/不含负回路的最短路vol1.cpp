#include <iostream>

using namespace std;

struct Edge
{
	int u, v;
	int cost;
};

int N, E;
Edge edge[200001];
int *dis;

int bellman_ford()
{
	dis[1] = 0;
	for (int i = 2; i <= N; i++)
		dis[i] = 100000;

	for (int i = 1; i <= N - 1; i++)
		for (int j = 1; j <= E; j++)
			if (dis[edge[j].v] > dis[edge[j].u] + edge[j].cost)
			{
				dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
			}
	return 0;
}

int main()
{
	cin >> N >> E;
	dis = new int[N + 1];

	for (int i = 1; i <= E; i++)
		cin >> edge[i].u >> edge[i].v >> edge[i].cost;

	bellman_ford();

	for (int i = 2; i <= N; i++)
		cout << dis[i] << endl;

	delete[] dis;
	return 0;
}
