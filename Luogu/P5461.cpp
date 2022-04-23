#include <iostream>

int Map[1100][1100];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	n = 1 << n;
	Map[0][n + 1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			Map[i][j] = Map[i - 1][j] ^ Map[i - 1][j + 1];
			std::cout << Map[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}