#include <iostream>
#include <cstdio>

int Num[9][9];

int main()
{
	int n;
	std::cin >> n;
	int x = 0, y = -1;
	for (int i = 1; i <= n * n;)
	{
		while (y < n - 1 && !Num[x][y + 1])
			Num[x][++y] = i++;
		while (x < n - 1 && !Num[x + 1][y])
			Num[++x][y] = i++;
		while (y && !Num[x][y - 1])
			Num[x][--y] = i++;
		while (x && !Num[x - 1][y])
			Num[--x][y] = i++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d", Num[i][j]);
		std::cout << '\n';
	}

	return 0;
}