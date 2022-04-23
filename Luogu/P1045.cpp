#include <iostream>
#include <cmath>
#include <cstring>

int Index, f[1001], res[1001], sav[1001];

void Result_1()
{
	std::memset(sav, 0, sizeof(sav));
	for (int i = 1; i <= 500; i += 1)
		for (int j = 1; j <= 500; j += 1)
			sav[i + j - 1] += res[i] * f[j];
	for (int i = 1; i <= 500; i += 1)
	{
		sav[i + 1] += sav[i] / 10;
		sav[i] %= 10;
	}
	std::memcpy(res, sav, sizeof(res));
}

void Result_2()
{
	std::memset(sav, 0, sizeof(sav));
	for (int i = 1; i <= 500; i += 1)
		for (int j = 1; j <= 500; j += 1)
			sav[i + j - 1] += f[i] * f[j];
	for (int i = 1; i <= 500; i += 1)
	{
		sav[i + 1] += sav[i] / 10;
		sav[i] %= 10;
	}
	std::memcpy(f, sav, sizeof(f));
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> Index;
	std::cout << (int)(std::log10(2) * Index + 1) << '\n';

	f[1] = 2;
	res[1] = 1;

	while (Index)
	{
		if (Index & 1)
			Result_1();
		Result_2();
		Index >>= 1;
	}
	res[1] -= 1;
	for (int i = 500; i >= 1; i--)
		if (i != 500 && i % 50 == 0)
			std::cout << '\n'
					  << res[i];
		else
			std::cout << res[i];

	return 0;
}