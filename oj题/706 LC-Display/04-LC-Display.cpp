#include <iostream>
#include <string>

using namespace std;

//0123456789
int font[10][15] = {
	{0, 1, 0,
	 1, 0, 1,
	 0, 0, 0,
	 1, 0, 1,
	 0, 1, 0
	 },
	{0, 0, 0,
	 0, 0, 1,
	 0, 0, 0,
	 0, 0, 1,
	 0, 0, 0
	},
	{0, 1, 0,
	 0, 0, 1,
	 0, 1, 0,
	 1, 0, 0,
	 0, 1, 0
	},
	{0, 1, 0,
	 0, 0, 1,
	 0, 1, 0,
	 0, 0, 1,
	 0, 1, 0
	},
	{0, 0, 0,
	 1, 0, 1,
	 0, 1, 0,
	 0, 0, 1,
	 0, 0, 0
	 },
	{0, 1, 0,
	 1, 0, 0,
	 0, 1, 0,
	 0, 0, 1,
	 0, 1, 0
	},
	{0, 1, 0,
	 1, 0, 0,
	 0, 1, 0,
	 1, 0, 1,
	 0, 1, 0
	},
	{0, 1, 0,
	 0, 0, 1,
	 0, 0, 0,
	 0, 0, 1,
	 0, 0, 0
	},
	{0, 1, 0,
	 1, 0, 1,
	 0, 1, 0,
	 1, 0, 1,
	 0, 1, 0
	},
	{0, 1, 0,
	 1, 0, 1,
	 0, 1, 0,
	 0, 0, 1,
	 0, 1, 0
	}
};

//输出偶数行
void print_evenline(int s, string str, int n)
{
	//for (int i = 0; i <= s; i++)
	{
		//第一个数
		cout << " ";
		for (int y = 0; y <= s; y++)
		{
			if (font[str[0] - '0'][3 * n + 1] == 0)
				cout << " ";
			else
				cout << "-";
		}
		cout << " ";

		//剩余的数
		for (int x = 1; x < str.length(); x++)
		{
			cout << " ";

			cout << " ";
			for (int y = 0; y <= s; y++)
				if (font[str[x] - '0'][3 * n + 1] == 0)
					cout << " ";
				else
					cout << "-";
			cout << " ";
		}
		cout << endl;
	}
}

//输出奇数行
void print_oddline(int s, string str, int n)
{
	for (int i = 0; i <= s; i++)
	{
		//第一个数
		if (font[str[0] - '0'][3 * n] == 1)
			cout << "|";
		else
			cout << " ";

		for (int y = 0; y <= s; y++)
			cout << " ";

		if (font[str[0] - '0'][3 * n + 2] == 1)
			cout << "|";
		else
			cout << " ";

		//剩余的数
		for (int x = 1; x < str.length(); x++)
		{
			cout << " ";
			if (font[str[x] - '0'][3 * n] == 1)
				cout << "|";
			else
				cout << " ";

			for (int y = 0; y <= s; y++)
				cout << " ";
			if (font[str[x] - '0'][3 * n + 2] == 1)
				cout << "|";
			else
				cout << " ";
		}
		cout << endl;
	}
}

//输出，从0开始记
void print(int s, string str)
{
	print_evenline(s, str, 0);
	print_oddline(s, str, 1);
	print_evenline(s, str, 2);
	print_oddline(s, str, 3);
	print_evenline(s, str, 4);
	cout << endl;
}

int main()
{
	int n;
	string str;

	while((cin >> n && n) && (cin >> str && str.compare("0") != 0))
		print(n - 1,str);

	return 0;
}
