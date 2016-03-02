#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int a[15];
	
	for (int i = 0; i < 5; i++)
		a[i] = 0;
		
	for (int i = 5; i < 15; i++)
		a[i] = 1;

	int count = 0;
	
	do
	{
		int init = 2;
		
		//按规律，进行计算一路的酒的数量
		for (int i = 0; i < 15; i++)
			if (a[i] == 0)
				init *= 2;
			else
				init--;
		
		//符合条件，输出序列，计数器加1
		if (init == 0)
		{
			for (int i = 0; i < 15; i++)
				if (a[i] == 0)
					cout << "a";
				else
					cout << "b";
			cout << endl;

			count++;
		}
	}while(next_permutation(a, a + 14));		//因为最后一家是花店，所以必为1，所以只需全排列前14个
	
	cout << count << endl;
	
	return 0;
}
