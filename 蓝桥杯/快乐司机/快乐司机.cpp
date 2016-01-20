#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Goods
{
	double value;
	int wight;
	bool operator<(const Goods &a)
	{
		return a.value < value;
	}
};

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
	vector<Goods> goods;
	Goods tmp;
	double sum = 0;

	cin >> n >> max;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.wight >> tmp.value;
		tmp.value /= tmp.wight;
		goods.push_back(tmp);
	}

	sort(goods.begin(), goods.end());

	int i = 0;
	while(max != 0)
	{
		sum += fun(goods[i], max);
		i++;
	}

	cout << setiosflags(ios::fixed) << setprecision(1)  << sum << endl;

	return 0;
}
