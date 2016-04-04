#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int find(string str, char ch)
{
	return str.find_first_of(ch);
}

int main()
{
	int pos = INT_MAX, tmp, len;
	char ch[] = {'a', 'e', 'i', 'o', 'u'};
	string str;

	cin >> str;
	len = str.length();

	for (int i = 0; i < 5; i++)
	{
		tmp = find(str, ch[i]);
		if (tmp != -1)
			pos = min(tmp + 1, pos);
	}

	if (pos == INT_MAX)
		pos = 0;

	cout << pos;

	return 0;
}
