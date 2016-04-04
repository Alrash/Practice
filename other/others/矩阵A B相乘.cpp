#include <iostream>

using namespace std;

int main()
{
	int des[200][200], A[200][200], B[200][200];
	int alen, wide, blen, sum = 0;

	cin >> alen >> wide >> blen;

	for (int i = 0; i < alen; i++)
		for (int j = 0; j < wide; j++)
			cin >> A[i][j];

	for (int i = 0; i < wide; i++)
		for (int j = 0; j < blen; j++)
			cin >> B[i][j];

	for (int i = 0; i < alen; i++)
		for (int j = 0; j < blen; j++)
		{
			sum = 0;
			for (int n = 0; n < wide; n++)
				sum += A[i][n] * B[n][j];
			des[i][j] = sum;
		}

	for (int i = 0; i < alen; i++)
	{
		for (int j = 0; j < blen; j++)
			cout << des[i][j] << " ";
		cout << endl;
	}

	return 0;
}