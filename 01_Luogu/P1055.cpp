#include <iostream>
#include <string>

std::string str;
int Tag;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> str;
	int len = str.size(), cnt = 1;
	for (int i = 0; i < len - 2; i++)
		if (str[i] != '-')
			Tag += (str[i] - '0') * (cnt++);
	Tag %= 11;
	if (Tag == 10)
	{
		if (str[len - 1] == 'X')
			std::cout << "Right\n";
		else
		{
			str = str.replace(str.end() - 1, str.end(), "X");
			std::cout << str;
		}
	}
	else
	{
		if (str[len - 1] == Tag + '0')
			std::cout << "Right\n";
		else
		{
			str[len - 1] = Tag + '0';
			std::cout << str;
		}
	}

	return 0;
}