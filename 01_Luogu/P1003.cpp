#include <iostream>

int Carpet[10001][4];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int CarpetNum, x, y;
	std::cin >> CarpetNum;
	for (int i = 0; i < CarpetNum; i++)
	{
		std::cin >> Carpet[i][0] >> Carpet[i][1] >> Carpet[i][2] >> Carpet[i][3];
		Carpet[i][2] += Carpet[i][0];
		Carpet[i][3] += Carpet[i][1];
	}
	std::cin >> x >> y;
	bool flag = false;
	for (int i = CarpetNum - 1; i >= 0; i--)
		if (x >= Carpet[i][0] && x <= Carpet[i][2] && y >= Carpet[i][1] && y <= Carpet[i][3])
		{
			std::cout << i + 1 << '\n';
			flag = !flag;
			break;
		}
	if (!flag)
		std::cout << -1 << '\n';

	return 0;
}