#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	tm nowtime;

	nowtime.tm_year = 2014 -1900;
	nowtime.tm_mon = 11 - 1;
	nowtime.tm_mday = 9 + 1000;
	nowtime.tm_hour = 0;
	nowtime.tm_min = 0;
	nowtime.tm_sec = 0;

	mktime(&nowtime);

	cout << nowtime.tm_year + 1900 << "/" << nowtime.tm_mon + 1 << "/" <<
		nowtime.tm_mday << endl << nowtime.tm_wday << endl;

	return 0;
}
