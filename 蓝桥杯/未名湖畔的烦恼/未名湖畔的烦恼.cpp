/*
 * 蓝桥杯算法训练题
 * 题目大意：有m个人还鞋，n个人借鞋，问有多少种方法让借鞋人有鞋接
 * 思路1：使用卡塔兰数c(n) = (2n)! / ((n + 1)!n!)(2n为总人数，n个人借鞋)
 *        然后将剩下的人插入区间，但是，这样可能会产生重复的组合
 * 思路2：使用堆栈模拟，定义还鞋人有限度高，即先紧还鞋人入堆栈
 *        以下dq变量是记录排列组合使用
 * */
/*
 * 别人提供的方法:f(m,n) = f(m - 1, n) + f(m, n - 1) (m >= n && n != 0)
 * 						   1  (n == 0)
 * 						   0  (m < n)
 * 动态规划
 * */
#include <iostream>
#include <deque>

using namespace std;

int m, n;
int tmp = 0, sum = 0;
deque<int> dq;

int fun()
{
	if (tmp < 0)
		return 0;

	if (m <= 0 || n <= 0)
	{
		/*for (int i = m; i > 0; i--)
			dq.push_back(1);

		for (int i = n; i > 0; i--)
			dq.push_back(-1);
		
		for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
			cout << *it << " ";
		cout << endl;*/
		sum++;

		/*for (int i = m; i > 0; i--)
			dq.pop_back();

		for (int i = n; i > 0; i--)
			dq.pop_back();*/

		return 0;
	}

	if (tmp == 0)
	{
		tmp++;
		//dq.push_back(1);
		m--;
		fun();
		m++;
		tmp--;
		//dq.pop_back();
	}
	else
	{
		tmp++;
		m--;
		//dq.push_back(1);
		fun();
		m++;
		tmp--;
		//dq.pop_back();

		tmp--;
		n--;
		//dq.push_back(-1);
		fun();
		n++;
		tmp++;
		//dq.pop_back();
	}

	return 0;
}

int main()
{
	cin >> m >> n;

	if (m < n)
		cout << "0" << endl;
	else
	{
		fun();
		cout << sum << endl;
	}

	return 0;
}
