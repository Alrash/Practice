#include <iostream>

using namespace std;

int main()
{
	int n, count;
	bool *flag;
	int *arr;

	cin >> n;
	flag = new bool[n];
	arr = new int[n];
	count = n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
		{
			flag[i] = false;
			count--;
		}
		else
			flag[i] = true;
	}

	cout << count << endl;

	for (int i = 0; i < n; i++)
		if (flag[i] == true)
			cout << arr[i] << " ";
	return 0;
}