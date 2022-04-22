#include <iostream>
#include <vector>

std::vector<int> Num[20];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	Num[0].push_back(1);
	for (int i = 1; i < n; i++)
	{
		Num[i].push_back(1);
		for (int j = 1; j < i; j++)
			Num[i].push_back(Num[i - 1][j - 1] + Num[i - 1][j]);
		Num[i].push_back(1);
	}
	for (int i = 0; i < n; i++)
	{
		int len = Num[i].size();
		for (int j = 0; j < len; j++)
			std::cout << Num[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}