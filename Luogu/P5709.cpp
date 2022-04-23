#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int AppleNum, EatTime, Time;
	std::cin >> AppleNum >> EatTime >> Time;
	if (EatTime)
	{
		double x = (double)Time / EatTime;
		AppleNum = (int)(AppleNum - x);
		if (AppleNum < 0)
			std::cout << "0\n";
		else
			std::cout << AppleNum << '\n';
	}
	else
		std::cout << "0\n";

	return 0;
}