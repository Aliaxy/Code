#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num;
	std::cin >> num;
	int Nature_1 = !(num & 1), Nature_2 = (num > 4 && num <= 12);
	std::cout << (Nature_1 && Nature_2) << ' ' << (Nature_1 || Nature_2) << ' ';
	std::cout << (Nature_1 + Nature_2 == 1) << ' ' << (Nature_1 + Nature_2 == 0) << '\n';

	return 0;
}