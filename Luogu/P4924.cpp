#include <iostream>

const int MAX = 501;

int Matrix[MAX][MAX], Temp[MAX][MAX], x, y, r;
bool z;

void Revolution()
{
	if (z)
	{
		for (int i = x - r; i <= x + r; i++)
			for (int j = y - r; j <= y + r; j++)
				Temp[x + y - j][y - x + i] = Matrix[i][j];
	}
	else
		for (int i = x - r; i <= x + r; i++)
			for (int j = y - r; j <= y + r; j++)
				Temp[x + j - y][x - i + y] = Matrix[i][j];
	for (int i = x - r; i <= x + r; i++)
		for (int j = y - r; j <= y + r; j++)
			Matrix[i][j] = Temp[i][j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Size, ChangeNum, cnt = 0;
	std::cin >> Size >> ChangeNum;
	for (int i = 1; i <= Size; i++)
		for (int j = 1; j <= Size; j++)
			Matrix[i][j] = ++cnt;
	while (ChangeNum--)
	{
		std::cin >> x >> y >> r >> z;
		Revolution();
	}
	for (int i = 1; i <= Size; i++)
	{
		for (int j = 1; j <= Size; j++)
			std::cout << Matrix[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}