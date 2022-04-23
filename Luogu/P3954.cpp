#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << (int)(a * 0.2 + b * 0.3 + c * 0.5) << '\n';

	return 0;
}