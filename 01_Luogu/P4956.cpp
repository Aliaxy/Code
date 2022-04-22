#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	int x, k = 1;
	bool flag = 1;
	while (flag)
	{
		for (x = 100; x >= 1; x--)
			if ((7 * x + 21 * k) * 52 == n)
			{
				std::cout << x << '\n';
				std::cout << k << '\n';
				flag = !flag;
				break;
			}
		k++;
	}

	return 0;
}