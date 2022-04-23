#include <iostream>

int Cube[40][40];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int x = 1, y = (n + 1) / 2;
	for (int i = 1; i <= n * n; i++)
	{
		Cube[x][y] = i;
		if (!Cube[(x - 2 + n) % n + 1][y % n + 1])
			x = (x - 2 + n) % n + 1, y = y % n + 1;
		else
			x = x % n + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			std::cout << Cube[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}