#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int replace(queue<int> &sign, stack<int> &stack, string &str)
{
	for (int i = 0; i < 2; i++)
	{
		str.replace(stack.top(), 1, "");
		stack.pop();
	}

	if (stack.empty())
		sign.pop();

	return 0;
}

bool check(queue<int> &q)
{
	int value[3];

	value[0] = q.front();
	q.pop();
	value[1] = q.front();
	value[2] = q.back();

	if (value[1] / 2 == value[0] / 2 && value[1] / 2 == value[2] / 2)
	{
		if (value[1] != value[0])
			return false;

		return true;
	}
	else
		if ((value[1] > value[0]) || (value[1] > value[2]))
			return true;

	return false;
}

int work(string &str)
{
	int len = str.length();
	queue<int> sign;		//+ - * /
	stack<int> stack;		//( )
	bool flag = false;

	sign.push(1);

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')	//maybe no need
			continue;

		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			switch (str[i])
			{
			case '+':sign.push(1);break;
			case '-':sign.push(0);break;
			case '*':sign.push(4);break;
			case '/':sign.push(3);break;
			}

			if (flag == true)
			{
				if (check(sign))
				{
					replace(sign, stack, str);
					i -= 2;
				}
				else
				{
					for (int i = 0; i < 2; i++)
						stack.pop();
				}

				flag = false;
				len = str.length();
			}

			if (stack.empty() && sign.size() > 1)
				sign.pop();
		}
		else
		{
			if (str[i] == ')')
				flag = true;

			stack.push(i);
		}
	}

	return 0;
}

int main()
{
	string str;

	cin >> str;
	str += "+";			//above

	work(str);
	str.replace(str.length() - 1, 1, "");

	cout << str;

	return 0;
}
