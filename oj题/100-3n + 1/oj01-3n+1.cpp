/* 3n + 1问题
 * 对于一个整数n，是奇数n = 3n + 1，是偶数 n = n / 2，计数多少次能得到n = 1
 * 次数记为n的长度，包括n和1
 * 现输入一个范围，求这里最大的长度
 * 例：22
 * 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
 * 长度为16
 * 解题思路：可能有重复计算的地方--dp
 * length = array[n变换后的值] + 1
 * 小处理：3n + 1 必为偶数，之后肯能做n / 2，可写到一起 n = n * 1.5 + 0.5
 * */
#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int arr[100000000];
deque<int> dq;

int update(int n)
{
	int sum = 1;

	dq.push_back(n);
	while (n != 1)
	{
		if (n < 100000000 && arr[n] != 0)
		{
			sum = sum + arr[n] - 1;
			break;
		}

		if ((n & 1) == 1)
		{
			n = 1.5 * n + 1;
			dq.push_back(n * 2);
			dq.push_back(n);
			sum += 2;
		}
		else
		{
			n /= 2;
			dq.push_back(n);
			sum++;
		}
	}

	for (int i = 0; dq.size() != 0; i++)
	{
		if (dq.front() < 100000000)
			arr[dq.front()] = sum - i;
		dq.pop_front();
	}
	dq.clear();

	return 0;
}

int main()
{
	memset(arr, 0, sizeof(arr));
	int start, end;
	int s, e;

	while ((cin >> start >> end))
	{
		//cin >> start >> end;

		e = end;
		s = start;
		if (start > end)
			swap(s, e);

		for (int i = s; i <= e; i++)
			update(i);
		
		cout << start << " " << end << " " << *max_element(arr + s, arr + e) << endl;
	}

	return 0;
}
