#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::string str;
	std::cin >> n >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] + n > 'z')
		{
			str[i] = 'a' + str[i] + n - 'z' - 1;
		}
		else
			str[i] += n;
	}
	std::cout << str;

	return 0;
}