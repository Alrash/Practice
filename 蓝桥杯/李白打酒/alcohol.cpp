#include <iostream>

using namespace std;

int sum = 0;

/*
 * 解释一下为什么flower>9而不是10
 * 因为最后一位固定为花店，可见前14家最后酒壶中酒剩余一斤*/
void fun(int store, int flower, int alcohol)
{
	if (store > 5 || flower > 9)
		return;

	fun(store + 1, flower, alcohol * 2);
	fun(store, flower + 1, alcohol - 1);

	if (store == 5 && flower == 9 && alcohol == 1)
		sum++;
}

int main(int argc, char *argv[])
{
	fun(0, 0, 2);

	cout << sum << endl;

	return 0;
}
