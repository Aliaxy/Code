#include <iostream>
#include <cstdlib>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Power;
	std::cin >> Power;
	for (int i = Power; ~i; i--)
	{
		int x;
		std::cin >> x;
		if (x)
		{
			if (x > 0 && i != Power)
				std::cout << '+';
			if (std::abs(x) > 1 || !i)
				std::cout << x;
			if (x == -1 && i)
				std::cout << '-';
			if (i == 1)
				std::cout
					<< 'x';
			if (i > 1)
				std::cout << "x^" << i;
		}
	}

	return 0;
}