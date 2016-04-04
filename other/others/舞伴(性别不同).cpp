//或者可以先找出下标，再用下标找性别
#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	string num;
	bool   sex;
}*student;

string adjust(string str, int len)
{
	if (str[0] > '9')	//character
		return str;

	for (int i = 0; i < len; i++)
		if (str == student[i].num)
			return student[i].name;
}

bool find(string str, int len)
{
	for (int i = 0; i < len; i++)
		if (str == student[i].name)
			return student[i].sex;
}

int dist(string str1, string str2, int len)
{
	bool sex[0];

	sex[0] = find(str1, len);
	sex[1] = find(str2, len);

	if (sex[0] ^ sex[1])
		return true;
	else
		return false;
}

int main()
{
	int n, m;
	string str[2];
	char sex;

	cin >> n;
	student = new Student[n];

	for (int i = 0; i < n; i++)
	{
		cin >> student[i].name >> student[i].num >> sex;
		if (sex == 'F')
			student[i].sex = false;
		else
			student[i].sex = true;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> str[0] >> str[1];

		str[0] = adjust(str[0], len);
		str[1] = adjust(str[1], len);

		if (dist(str[0], str[1], len))
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}

	delete[] student;

	return 0;
}
