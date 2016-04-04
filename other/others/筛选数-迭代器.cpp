/*
 *使用了list容器与迭代器
 */
#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n;
	list<int> l;
	list<int>::iterator itor, tmp;
	int pos = 0;

	cin >> n;

	l.clear();
	for (int i = 1; i <= n; i++)
		l.push_back(i);

	itor = l.begin();

	do
	{
		pos = (pos + 1) % 3;

		if (pos == 0)
		{
			tmp = itor++;
			l.erase(tmp);
		}
		else
			itor++;

		if (itor == l.end())
			itor = l.begin();
	} while (l.size() != 1);

	cout << l.front();

	return 0;
}
