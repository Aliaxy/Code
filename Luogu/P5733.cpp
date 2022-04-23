#include <cctype>
#include <iostream>
#include <string>

std::string str;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> str;
	for (int i = 0; i < str.size(); i++)
		str[i] = std::towupper(str[i]);
	std::cout << str;

	return 0;
}