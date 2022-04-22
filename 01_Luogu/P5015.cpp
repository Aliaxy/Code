#include <iostream>
#include <string>

std::string str;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::getline(std::cin, str);
	int len = str.size(), cnt = 0;
	for (int i = 0; i < len; i++)
		if (str[i] != ' ' && str[i] != '\n')
			cnt++;
	std::cout << cnt;

	return 0;
}