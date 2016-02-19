#include <iostream>
#include <set>

using namespace std;

bool find(int xiang, int rui, int sheng, int hui, int san, int yang, int xian, int qi)
{
	set<int> s;

	s.insert(xiang);
	s.insert(rui);
	s.insert(sheng);
	s.insert(hui);
	s.insert(san);
	s.insert(yang);
	s.insert(xian);
	s.insert(qi);

	if (s.size() != 8)
		return false;

	int x = xiang * 1000 + rui * 100 + sheng * 10 + hui;
	int y = san * 1000 + yang * 100 + xian * 10 + rui;
	int z = san * 10000 + yang * 1000 + sheng * 100 + rui * 10 + qi;

	if (x + y == z)
		return true;
	return false;
}

int main()
{
	int xiang, rui, sheng, hui, san, yang, xian, qi;
	
	for (xiang = 0; xiang < 10; xiang++)
		for (rui = 0; rui < 10; rui++)
			for (sheng = 0; sheng < 10; sheng++)
				for (hui = 0; hui < 10; hui++)
					for (san = 0; san < 10; san++)
						for (yang = 0; yang < 10; yang++)
							for (xian = 0; xian < 10; xian++)
								for (qi = 0; qi < 10; qi++)
									if (find(xiang, rui, sheng, hui, san, yang, xian, qi))
										cout << xiang << " " << rui << " "
											<< sheng << " " << hui << " "
											<< san << " " << yang << " "
											<< xian << " " << qi << endl;
	return 0;
}
