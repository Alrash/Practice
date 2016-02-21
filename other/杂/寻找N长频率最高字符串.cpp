/*
*len >= N
*frequece相同，输出长度长的，出现最早的
*/
#include <iostream>
#include <cstring>

using namespace std;

int Copy(char str[], char cmp[], int n);
bool Cmp(char str[], char cmp[], int n);

int main()
{
	int n;
	char str[61], *cmp, arr[3600][61];
	int len = 0, count = 1, max = 0, pos = 0, alen = 0, clen = 0;
	bool flag = false;

	cin >> n >> str;
	len = strlen(str);
	cmp = new char[len + 1];
	cmp[len] = '\0';

	for (;n <= len - max; n++)
	{
		for (int i = 0; i < len - n * max; i++)
		{
			flag = false;
			Copy(str + i, cmp, n);
			for (int j = 0; j < alen; j++)
				if (!strcmp(arr[j], cmp))
				{
					flag = true;
					break;
				}

			if (flag == true)
				continue;

			strcpy(arr[alen], cmp);
			alen++;
			count = 1;

			for (int j = i + 1; j < len - n; j++)
			{
				if (str[j] == cmp[0])
				{
					if (Cmp(str + j, cmp, n))
					{
						count++;
					}
				}
			}
			if (max <= count)
			{
				if (max == count && clen == n)
					continue;
				max = count;
				pos = alen - 1;
				clen = n;
			}
		}
	}

	cout << arr[pos];
	delete[] cmp;
	return 0;
}

int Copy(char str[], char cmp[], int n)
{
	for (int i = 0; i < n; i++)
		cmp[i] = str[i];
	cmp[n] = '\0';

	return 0;
}

bool Cmp(char str[], char cmp[], int n)
{
	for (int i = 1; i < n; i++)
		if (str[i] != cmp[i])
			return false;

	return true;
}