#include <iostream>

int Factorial(int x)
{
	if (x == 1)
		return 1;
	return x * Factorial(x - 1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::cout << Factorial(n) << '\n';

	return 0;
}