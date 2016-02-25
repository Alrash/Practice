/*
 * LIS[i] = max(LIS[j]) + 1 (0 < j < i, a[j] < a[i])
 *        = max(LIS[j]) (a[j] == a[i])
 *        = 1 (a[i] 恒< a[1...i - 1])
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

/*
 * 存放大象数据的结构体
 * */
struct Node
{
	int weight;			//体重
	int small;			//智商
	int num;			//序号

	/* 重载小于号，sort使用
	 * 当智商和体重相等时，按序号从小到大排序
	 * */
	bool operator<(const Node &node) const
	{
		if (this->small == node.small)
		{
			if (this->weight == node.weight)
				return this->num < node.num;
			else
				return this->weight > node.weight;
		}
		else
			return this->small > node.small;
	}
};

//vector<vector<int> > dp(1005, vector<int>(1005));
//vector<vector<int> > ans(1005, vector<int>(1005));
vector<int> dp(1005, 0);		//存放LIS[i]的长度
vector<int> ans(1005, 0);		//记录前一个序号

/*
 * a[0].weight = 0用于LIS[i]条件3
 * 时间负责度O(n^2)
 * */
void LIS(const vector<Node> &vt)
{
	dp[1] = 1;					//当元素只有一个时，LIS长度必为1

	for (int i = 2, j; i < vt.size(); i++)
	{
		ans[i] = 0;
		for (j = i - 1; j >= 0; j--)
		{//LIS[i] = Max(LIS(j)) +? 1
			if (vt[i].weight > vt[j].weight)
			{//+ 1
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					ans[i] = j;
				}
			}
			else if (vt[i].weight == vt[j].weight)
			{//= LIS[j]
				if (dp[i] < dp[j])
				{
					dp[i] = dp[j];
					ans[i] = ans[j];
				}
			}
		}
	}
}

/*
 * 递归输出答案
 * */
void getAns(int x, const vector<Node> &vt)
{
	if (ans[x] == 0)
	{
		cout << vt[x].num << endl;
		return;
	}
	else
	{
		getAns(ans[x], vt);
		cout << vt[x].num << endl;
	}
}

int main()
{
	vector<Node> vt;
	Node tmp;

	/*
	 * a[0] 恒< a[i]
	 * */
	tmp.num = 0;
	tmp.weight = 0;
	tmp.small = 0xffff;
	vt.push_back(tmp);

	//读取数据
	int i = 0;
	while (scanf("%d %d", &tmp.weight, &tmp.small) == 2)
	{
		tmp.num = ++i;
		vt.push_back(tmp);
	}

	sort(vt.begin(), vt.end());
	
	LIS(vt);

	/*
	 * 找寻最长的递增序列长度
	 * 例如：2 3 1
	 * dp 为 1 2 1
	 * 则最后一位不是最长的递增序列长度
	 * */
	int pos = 1;
	for (int i = 2; i < vt.size(); i++)
		pos = dp[i] > dp[pos] ? i : pos;
	
	cout << dp[pos] << endl;
	getAns(pos, vt);

	return 0;
}
