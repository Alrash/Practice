#include <iostream>
#include <set>

using namespace std;

/*int main()
{
	int sum = 999;

	for (int i = 3; i < 999; i++)
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;

	cout << sum << endl;

	return 0;
}*/

int main()
{
	int sum = 0;
	int end1 = 1000 / 5, end2 = 1000 / 3;
	set<int> s;

	for (int i = 1; i < end1; i++)
	{
		s.insert(3 * i);
		s.insert(5 * i);
	}

	for (int i = end1; i <= end2; i++)
		s.insert(3 * i);

	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		sum += *iter;

	cout << sum << endl;

	return 0;
}
