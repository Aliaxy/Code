#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, cnt = 1;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cnt < 10)
				std::cout << 0;
			std::cout << cnt;
			cnt++;
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	cnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			std::cout << "  ";
		for (int j = 0; j <= i; j++)
		{
			if (cnt < 10)
				std::cout << 0;
			std::cout << cnt;
			cnt++;
		}
		std::cout << '\n';
	}

	return 0;
}