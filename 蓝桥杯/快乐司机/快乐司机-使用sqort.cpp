#include <iostream>
#include <cstdlib>
#include <iomanip>

#define N 50000

using namespace std;

struct Goods
{
	double value;
	int wight;
};

int cmp(const void *a, const void *b)
{
	return (((Goods *)b)->value - ((Goods *)a)->value) * 1000;
}

double fun(const Goods &goods, int &max)
{
	if (goods.wight < max)
	{
		max -= goods.wight;
		return goods.wight * goods.value;
	}
	else
	{
		double money = max * goods.value;
		max = 0;
		return money;
	}
}

int main()
{
	int n, max;
	Goods goods[N];
	double sum = 0;

	cin >> n >> max;
	for (int i = 0; i < n; i++)
	{
		cin >> goods[i].wight >> goods[i].value;
		goods[i].value /= goods[i].wight;
	}

	qsort(goods, n, sizeof(Goods), cmp);

	int i = 0;
	while (max != 0)
	{
		sum += fun(goods[i], max);
		i++;
	}

	cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;

	return 0;
}