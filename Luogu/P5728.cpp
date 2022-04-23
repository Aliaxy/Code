#include <iostream>
#include <cstdio>

int Score[1000][4];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
		{
			std::cin >> Score[i][j];
			Score[i][3] += Score[i][j];
		}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (std::abs(Score[i][0] - Score[j][0]) <= 5 &&
				abs(Score[i][1] - Score[j][1]) <= 5 &&
				abs(Score[i][2] - Score[j][2]) <= 5 &&
				abs(Score[i][3] - Score[j][3]) <= 10)
				cnt++;
		}
	std::cout << cnt << '\n';

	return 0;
}