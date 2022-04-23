#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Length, cnt = 1;
	std::cin >> Length;
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Length - i; j++)
		{
			if (cnt < 10)
				std::cout << '0' << cnt;
			else
				std::cout << cnt;
			cnt++;
		}
		std::cout << '\n';
	}

	return 0;
}