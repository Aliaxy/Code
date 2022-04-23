#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long n;
	std::cin >> n;
	for (int i = 1; i * i <= n; i++)
		std::cout << i * i << ' ';

	return 0;
}