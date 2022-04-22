#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int EatNum;
	std::cin >> EatNum;
	std::string str = EatNum != 1 && EatNum ? "apples.\n" : "apple.\n";
	std::cout << "Today, I ate " << EatNum << " " << str;

	return 0;
}