#include <iostream>

long long n, x = 0, sss = 0, ss = 1, i = 2, t = 1;
int a[10001], s[10001];

void jc(int x)
{
	for (int i = 1; i <= t; i++)
	{
		s[i] = s[i] * x;
	}
	for (int i = 1; i <= t; i++)
	{
		if (s[i] >= 10)
		{
			long long add = s[i] / 10;
			s[i + 1] += add;
			s[i] = s[i] % 10;
			if (i + 1 > t)
				t = i + 1;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	s[1] = 1;
	std::cin >> n;
	while (sss < n)
	{
		a[++x] = i;
		sss += i;
		i++;
	}
	a[sss - n - 1] = 0;
	for (int i = 1; i <= x; i++)
	{
		if (a[i] != 0)
			std::cout << a[i] << ' ';
		if (a[i] != 0)
			jc(a[i]);
	}
	std::cout << '\n';
	for (int i = t; i >= 1; i--)
		std::cout << s[i];
	std::cout << '\n';

	return 0;
}