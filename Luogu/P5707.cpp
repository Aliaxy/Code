#include <iostream>
#include <cmath>

double s, v, m;
int n, a, t, b;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> s >> v;
	n = 8 * 60 + 24 * 60;
	t = std::ceil(s / v) + 10;
	n = n - t;
	if (n >= 24 * 60)
		n -= 24 * 60;
	b = n % 60;
	a = n / 60;
	if (a < 10)
	{
		if (b < 10)
			std::cout << "0" << a << ":0" << b;
		else
			std::cout << "0" << a << ":" << b;
	}
	else
	{
		if (b < 10)
			std::cout << a << ":0" << b;
		else
			std::cout << a << ":" << b;
	}
	return 0;
}