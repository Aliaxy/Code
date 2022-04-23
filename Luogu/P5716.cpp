#include <iostream>

int MonthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int Year, Month;
	std::cin >> Year >> Month;
	if (Year % 100 && !(Year % 4) || !(Year % 400))
		MonthDay[1]++;
	std::cout << MonthDay[Month - 1] << '\n';

	return 0;
}