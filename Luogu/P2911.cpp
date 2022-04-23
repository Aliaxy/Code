#include <iostream>
#include <algorithm>

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Num[3];
	for (int i = 0; i < 3; i++)
		std::cin >> Num[i];
	std::sort(Num, Num + 3, cmp);
	if (Num[1] <= Num[0] - Num[2] + 1)
		std::cout << 1 + Num[1] + Num[2] << '\n';
	else
		std::cout << 2 + Num[0] + (Num[1] - Num[0] + Num[2] - 1) / 2 << '\n';

	return 0;
}