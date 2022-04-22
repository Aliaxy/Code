#include <iostream>

bool IsPrime(int x)
{
	if (x <= 1)
		return false;
	if (x == 2 || x == 3)
		return true;
	if (x % 6 != 1 && x % 6 != 5)
		return false;
	for (int i = 5; i * i <= x; i += 6)
		if (x % i == 0 || x % (i + 2) == 0)
			return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		if (IsPrime(num))
			std::cout << num << ' ';
	}
	std::cout << '\n';

	return 0;
}