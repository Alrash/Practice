/*
 * 对给定的序列重新排序，要求生成比序列大的最小序列，若原序列最大，则倒序输出
 * 例：1,2,3 -> 1,3,2
 *     1,1,5 -> 1,5,1
 *     3,2,1 -> 1,2,3
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int len;
	bool flag = false;

	cin >> str;
	len = str.length();

	for (int i = len - 1, pos; i > 0; i--)
	{
		if (str[i - 1] <= str[i] && flag)
		{
			pos = str.find_first_not_of(str[i], i);

			if (pos == -1)
				pos = i;

			swap(str[i - 1], str[pos]);
			
			break;
		}
		else
		{
			str += str[i - 1];
			str.replace(i - 1, 1, "");
			flag = true;
		}
	}

	cout << str;

	return 0;
}
