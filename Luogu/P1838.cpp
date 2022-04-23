#include <iostream>
#include <string>

std::string str;
int Map[4][4];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> str;
	int len = str.length();
	if (len < 9)
	{
		if (len % 2)
			std::cout << "xiaoa wins.\n";
		else
			std::cout << "uim wins.\n";
	}
	else
	{
		for (int i = 0; i < 9; i += 2)
			Map[(str[i] - '1') / 3][(str[i] - '1') % 3] = 1;
		for (int j = 0; j < 3; j++)
		{
			if (Map[j][0] + Map[j][1] + Map[j][2] == 3 || Map[0][j] + Map[1][j] + Map[2][j] == 3 || Map[0][0] + Map[1][1] + Map[2][2] == 3 || Map[0][2] + Map[1][1] + Map[2][0] == 3)
			{
				std::cout << "xiaoa wins.\n";
				return 0;
			}
			else if (Map[j][0] + Map[j][1] + Map[j][2] == 0 || Map[0][j] + Map[1][j] + Map[2][j] == 0 || Map[0][0] + Map[1][1] + Map[2][2] == 0 || Map[0][2] + Map[1][1] + Map[2][0] == 0)
			{
				std::cout << "uim wins.\n";
				return 0;
			}
		}
		std::cout << "drew.\n";
	}

	return 0;
}