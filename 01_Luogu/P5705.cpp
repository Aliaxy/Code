#include <iostream>
#include <string>
#include <algorithm>

std::string str;

int main()
{
	std::cin >> str;
	std::reverse(str.begin(), str.end());
	std::cout << str << '\n';

	return 0;
}