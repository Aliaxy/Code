#include <iostream>
#include <string>
#include <algorithm>

std::string str;
int Cnt[26];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (std::cin >> str)
	{
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				Cnt[str[i] - 'A']++;
		}
	}
	int MaxNum = 0;
	for (int i = 0; i < 26; i++)
		MaxNum = std::max(MaxNum, Cnt[i]);
	for (int i = MaxNum; i; i--)
	{
		for (int j = 0; j < 26; j++)
			if (Cnt[j] >= i)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}
	for (int i = 0; i < 26; i++)
		std::cout << (char)(i + 'A') << ' ';

	return 0;
}