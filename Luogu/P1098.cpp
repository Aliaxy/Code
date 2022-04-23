#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string str;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Mode, Repeat, IsReverse;
	std::cin >> Mode >> Repeat >> IsReverse;
	std::cin >> str;

	int pos = 0;
	pos = str.find('-', pos);
	while (~pos)
	{
		if (std::isalpha(str[pos - 1]) && std::isalpha(str[pos + 1]) || std::isdigit(str[pos - 1]) && std::isdigit(str[pos + 1]))
		{
			if (str[pos - 1] + 1 == str[pos + 1])
				str = str.erase(pos, 1);
			else if ((str[pos - 1] + 1 < str[pos + 1]))
			{
				int a = str[pos - 1] + 1, b = str[pos + 1], temp = pos;
				str = str.erase(pos, 1);
				for (int i = a; i < b; i++)
				{
					if (Mode == 3)
						str.insert(pos, Repeat, '*');
					else
						str.insert(pos, Repeat, (char)i);
					pos += Repeat;
				}
				if (Mode == 2)
					std::transform(str.begin() + temp, str.begin() + pos, str.begin() + temp, ::toupper);
				if (IsReverse == 2)
					std::reverse(str.begin() + temp, str.begin() + pos);
			}
		}
		pos++;
		pos = str.find('-', pos);
	}
	std::cout << str << '\n';

	return 0;
}