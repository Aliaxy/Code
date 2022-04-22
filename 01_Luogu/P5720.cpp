#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Length, i;
	std::cin >> Length;
	for (i = 1; 1 << i < Length; i++)
		;
	std::cout << i << '\n';
	return 0;
}