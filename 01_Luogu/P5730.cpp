#include <iostream>

char c[10][5][4] =
	{
		"XXX", // 0
		"X.X",
		"X.X",
		"X.X",
		"XXX",
		"..X", // 1
		"..X",
		"..X",
		"..X",
		"..X",
		"XXX", // 2
		"..X",
		"XXX",
		"X..",
		"XXX",
		"XXX", // 3
		"..X",
		"XXX",
		"..X",
		"XXX",
		"X.X", // 4
		"X.X",
		"XXX",
		"..X",
		"..X",
		"XXX", // 5
		"X..",
		"XXX",
		"..X",
		"XXX",
		"XXX", // 6
		"X..",
		"XXX",
		"X.X",
		"XXX",
		"XXX", // 7
		"..X",
		"..X",
		"..X",
		"..X",
		"XXX", // 8
		"X.X",
		"XXX",
		"X.X",
		"XXX",
		"XXX", // 9
		"X.X",
		"XXX",
		"..X",
		"XXX"};
char ans[10][1000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, s = 0;
	std::cin >> n;
	while (n--)
	{
		char a;
		std::cin >> a;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 3; j++)
				ans[i][s + j] = c[a - '0'][i][j];
		for (int i = 0; i < 5; i++)
			ans[i][s + 3] = '.';
		s += 4;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < s - 1; j++)
			std::cout << ans[i][j];
		std::cout << '\n';
	}

	return 0;
}