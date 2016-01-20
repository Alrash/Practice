#include <iostream>
#include <set>

using std::multiset;
using std::cin;
using std::cout;
using std::endl;

struct cmp
{
	bool operator()(const int &a, const int &b)const
	{
		return a > b;
	}
};

int main()
{
	multiset<int, cmp> myset;
	for (int i = 0, tmp; i < 3; i++)
	{
		cin >> tmp;
		myset.insert(tmp);
	}

	for (multiset<int, cmp>::iterator iter = myset.begin(); iter != myset.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
