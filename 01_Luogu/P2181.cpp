#include <iostream>

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);
	unsigned long long n;
	std::cin >> n;
	std::cout << n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
	return 0;
}