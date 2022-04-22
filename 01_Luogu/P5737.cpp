#include <iostream>
#include <vector>

std::vector<int> LeapYear;

bool IsLeap(int x)
{
	if (x % 100 && !(x % 4) || !(x % 400))
		return true;
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x, y;
	std::cin >> x >> y;
	for (int i = x; i <= y; i++)
		if (IsLeap(i))
			LeapYear.push_back(i);
	std::cout << LeapYear.size() << '\n';
	for (int i = 0; i < LeapYear.size(); i++)
		std::cout << LeapYear[i] << ' ';

	return 0;
}