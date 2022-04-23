#include <iostream>
#include <algorithm>

int Map[50][50],
	Dp[100][50][50];

int main()
{
	std::ios::sync_with_stdio(false);
	int Height, Width;
	std::cin >> Height >> Width;
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++)
			std::cin >> Map[i][j];

	for (int k = 1; k <= Height + Width - 2; k++)
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Height; j++)
			{
				if (k - i < 0 || k - j < 0)
					continue;

				if (i - 1 < 0 && j - 1 >= 0)
					Dp[k][i][j] = std::max(Dp[k - 1][i][j], Dp[k - 1][i][j - 1]) + Map[i][k - i] + Map[j][k - j];
				else if (j - 1 < 0 && i - 1 >= 0)
					Dp[k][i][j] = std::max(Dp[k - 1][i][j], Dp[k - 1][i - 1][j]) + Map[i][k - i] + Map[j][k - j];
				else if (j - 1 < 0 && i - 1 < 0)
					Dp[k][i][j] = Dp[k - 1][i][j] + Map[i][k - i] + Map[j][k - j];
				else
					Dp[k][i][j] = std::max(std::max(Dp[k - 1][i][j], Dp[k - 1][i - 1][j]), std::max(Dp[k - 1][i][j - 1], Dp[k - 1][i - 1][j - 1])) + Map[i][k - i] + Map[j][k - j];
				if (i == j)
					Dp[k][i][j] -= Map[i][k - i];
			}
	std::cout << Dp[Height + Width - 2][Height - 1][Height - 1] << "\n";

	return 0;
}