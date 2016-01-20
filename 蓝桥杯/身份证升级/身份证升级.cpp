#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int arr[] = {7, 9, 10, 5, 8, 4, 6, 3, 7, 9, 10, 5, 8, 4, 2}, sum = 2 * 1 + 1 * 9;

	cin >> str;
	for(int i = 0; i < str.length(); i++)
		sum += arr[i] * (str.at(i) - 48);

	str.insert(6, "19");

	sum = 10 - ((sum % 11) + 9) % 11;

	if (sum == 10)
		str += 'x';
	else
		str += (char)(sum + 48);		//str += to_string(sum);	//c11

	cout << str << endl;

	return 0;
}
/*
int main()
{
	string str;
	int arr[] = {7, 9, 10, 5, 8, 4, 6, 3, 7, 9, 10, 5, 8, 4, 2}, sum = 2 * 1 + 1 * 9;
	char ch[] = {'1', '0', 'x', '9', '8', '7', '6', '5', '4', '3', '2'};

	cin >> str;
	for(int i = 0; i < str.length(); i++)
		sum += arr[i] * (str.at(i) - 48);

	str.insert(6, "19");

	sum = sum % 11;

	str += ch[sum];

	cout << str << endl;

	return 0;
}*/