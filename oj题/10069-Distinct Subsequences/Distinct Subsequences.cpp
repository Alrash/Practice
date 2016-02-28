/*
 * 本程序未AC，原因：中间数可能超出范围
 * 高精度计算
 * 因为采用动态规划，使用二维数组记录中间值，所以这里提供以下方案
 * 解决方案：1.char的三维数组
 * 			 2.struct中定义一个数组，用于存放中间数，需要重载[][]，operator+，<<等等
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int LEN = 10005;

vector<vector<int>> dp(LEN, vector<int>(LEN));

/*
 * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] (str[i] == sub[j])
 *          = dp[i - 1][j]                    (str[i] != sub[j])
 * */
int numOfSub(char str[], char sub[], int strl, int subl)
{
	for (int i = 1; i < strl; i++)
		for (int j = 1; j < subl; j++)
			if (str[i] == sub[j])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j];

	return dp[strl - 1][subl - 1];
}

int main()
{
	char str[LEN], sub[LEN];
	//strl -- strlen	subl -- sublen
	int strl, subl;
	int n;

	cin >> n;

	for (int i = 0; i < LEN; i++)
		dp[0][i] = 0;
	for (int i = 0; i < LEN; i++)
		dp[i][0] = 1;

	while (n--)
	{
		scanf("%s%s", &str[1], &sub[1]);

		strl = strlen(str + 1);
		subl = strlen(sub + 1);

		cout << numOfSub(str, sub, strl + 1, subl + 1) << endl;
	}

	return 0;
}
