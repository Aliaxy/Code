#include <iostream>
#include <string>
#include <algorithm>

std::string a, b;
int Num[501];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> a >> b;
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	if (a.size() < b.size())
	{
		std::string temp = a;
		a = b;
		b = temp;
	}
	int len = b.size();
	for (int i = 0; i < len; i++)
	{
		Num[i] += a[i] - '0' + b[i] - '0';
		while (Num[i] > 9)
		{
			Num[i] -= 10;
			Num[i + 1]++;
		}
	}
	len = a.size();
	for (int i = b.size(); i < len; i++)
	{
		Num[i] += a[i] - '0';
		while (Num[i] > 9)
		{
			Num[i] -= 10;
			Num[i + 1]++;
		}
	}
	std::reverse(Num, Num + len + 1);
	if (Num[0])
		std::cout << Num[0];
	for (int i = 1; i < len + 1; i++)
		std::cout << Num[i];

	return 0;
}