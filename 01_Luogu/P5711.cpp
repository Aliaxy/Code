#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num;
	std::cin >> num;
	std::cout << (num % 100 && !(num % 4) || !(num % 400)) << '\n';

	return 0;
}