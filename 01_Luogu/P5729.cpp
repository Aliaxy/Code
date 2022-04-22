#include <iostream>

int Cube[21][21][21];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x, y, z;
	std::cin >> x >> y >> z;
	int CutNum;
	std::cin >> CutNum;
	while (CutNum--)
	{
		int a1, b1, c1, a2, b2, c2;
		std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		for (int i = a1; i <= a2; i++)
			for (int j = b1; j <= b2; j++)
				for (int k = c1; k <= c2; k++)
					Cube[i][j][k] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			for (int k = 1; k <= z; k++)
				if (!Cube[i][j][k])
					cnt++;
	std::cout << cnt << '\n';

	return 0;
}