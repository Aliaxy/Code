#include <iostream>

const int MAX = 102;

char Map[MAX][MAX];
int Reslut[MAX][MAX], n, m;

int main()
{

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			std::cin >> Map[i][j];
			if (Map[i][j] == '*')
			{
				Reslut[i + 1][j + 1]++;
				Reslut[i + 1][j - 1]++;
				Reslut[i + 1][j]++;
				Reslut[i][j + 1]++;
				Reslut[i][j - 1]++;
				Reslut[i - 1][j]++;
				Reslut[i - 1][j + 1]++;
				Reslut[i - 1][j - 1]++;
			}
		}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (Map[i][j] == '*')
				std::cout << "*";
			else
				std::cout << Reslut[i][j];
		}
		std::cout << '\n';
	}
	return 0;
}