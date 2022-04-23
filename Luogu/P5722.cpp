#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, sum = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		sum += i;
	std::cout << sum << '\n';

	return 0;
}