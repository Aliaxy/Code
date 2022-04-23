#include <algorithm>
#include <iostream>
#include <string>

std::string num[20];

bool Cmp(std::string a, std::string b)
{
	return a + b > b + a;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> num[i];
	std::sort(num, num + n, Cmp);
	for (int i = 0; i < n; i++)
		std::cout << num[i];
	std::cout << '\n';

	return 0;
}