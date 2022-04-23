#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num;
	std::cin >> num;
	for (int i = num; i; i++)
	{
		int x = 0, y = 0;
		int z = std::sqrt(i);
		for (int j = 2; j < z; j++)
			if (i % j == 0)
				x += j + i / j;
		if (i % z == 0)
			x += z;
		x++;
		int xx = std::sqrt(x);
		for (int j = 2; j < xx; j++)
			if (x % j == 0)
				y += j + x / j;
		y++;
		if (y == i && i != x)
		{
			std::cout << i << ' ' << x << '\n';
			break;
		}
	}

	return 0;
}