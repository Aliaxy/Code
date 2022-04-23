#include <iostream>
#include <string>
#include <algorithm>

const int Prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int Sum[26];

void Judge()
{
	int minn = 100, maxn = 1;
	for (int i = 0; i < 26; i++)
	{
		if (Sum[i])
			minn = std::min(minn, Sum[i]);
		maxn = std::max(maxn, Sum[i]);
	}
	for (int i = 0; i < 25; i++)
		if (maxn - minn == Prime[i])
		{
			std::cout << "Lucky Word\n";
			std::cout << Prime[i] << '\n';
			return;
		}
	std::cout << "No Answer\n";
	std::cout << "0\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str;
	std::cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++)
		Sum[str[i] - 'a']++;
	Judge();

	return 0;
}