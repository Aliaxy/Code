#include <iostream>
#include <cstring>

const int MAX = 5e3 + 1;
int Fac[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int TestCase;
	std::cin >> TestCase;
	while (TestCase--)
	{
		int n, x;
		std::cin >> n >> x;
		std::memset(Fac, 0, sizeof(Fac));
		Fac[0] = 1;
		int len = 1;
		for (int i = 2; i <= n; i++)
		{
			int Push = 0;
			for (int j = 0; j < len; j++)
			{
				Fac[j] = Fac[j] * i + Push;
				Push = Fac[j] / 10;
				Fac[j] %= 10;
			}
			while (Push)
			{
				Fac[len] = Push % 10;
				len++;
				Push /= 10;
			}
		}
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			if (Fac[i] == x)
				sum++;
		}
		std::cout << sum << '\n';
	}

	return 0;
}