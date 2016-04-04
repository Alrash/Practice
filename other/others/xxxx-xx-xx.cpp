#include <iostream>

using namespace std;

bool Isyear(int year)
{
	if (year % 400 == 0)
		return true;
	else
		return false;
}

bool Isyear(int year, bool full)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
			return Isyear(year);
		else
			return true;
	}
	else
		return false;
}

int Count(int year, bool &flag)
{
	int count = 0;

	for (int i = 2000; i < year; i += 4)
	{
		if (year % 100 == 0 && Isyear(i) == false)
			continue;
		count++;
	}

	if (Isyear(year, true))
	{
		count++;
		flag = true;
	}

	return count;
}

int write(int d[], int day[], int sum)
{
	d[0] = sum + 12;

	for (int i = 1; i < 12; i++)
		d[i] = d[i - 1] + day[i - 1];

	return 0;
}

int dist(int d[])
{//distinguish
	int count = 0;

	for (int i = 0; i < 12; i++)
	{
		d[i] %= 7;
		if (d[i] == 1)
			count++;
	}

	return count;
}

int main()
{
	int year;
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };	//only use 0-10(1-11 month)
	int d[12], count = 0, sum = 0;
	bool flag = false;

	cin >> year;

	count = Count(year, flag);
	sum = count + 365 * (year - 1998);
	if (flag == true)
	{
		sum -= 1;
		day[1] += 1;
	}
	write(d, day, sum);
	count = dist(d);

	cout << count;

	return 0;
}
